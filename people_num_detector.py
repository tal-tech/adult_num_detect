
from mmdet.apis import inference_detector, init_detector
import base64
import os
import cv2
import numpy as np


# # from config.config import ROOT_PATH
# from config import ROOT_PATH

ROOT_PATH = os.path.abspath(os.path.dirname(__file__)).split('config')[0]





def inference(model,image):
    num_stu = 0
    num_adult = 0
    student_body_rectangles = []
    adult_body_rectangles = []
    results = {'student':{'student_num':num_stu, 'student_body_rectangles':student_body_rectangles},
        'adult': {'adult_num':num_adult, 'adult_body_rectangles':adult_body_rectangles}}

    result = inference_detector(model, image)

    labels_pred = [
         np.full(bbox.shape[0], j, dtype=np.int32)
        for j, bbox in enumerate(result)]

    labels_pred = np.concatenate(labels_pred)

    if len(labels_pred) == 0:
        return results

    det_result = []
    for idx, res in enumerate(result):
        for r in res:
            det_result.append(r)

    # # post precess
    det_result = np.vstack(det_result)
    keep = nms(det_result, 0.85)

    det_result = det_result[keep]
    labels_pred = labels_pred[keep]


    stu_idx = np.where(labels_pred == 0)
    adult_idx = np.where(labels_pred == 1)

    num_stu = len(list(stu_idx)[0])
    num_adult = len(list(adult_idx)[0])
    stu_boxes = det_result[stu_idx]
    adult_boxes = det_result[adult_idx]

    for b in stu_boxes:
        x1, y1, x2, y2 = int(b[0]), int(b[1]), int(b[2]), int(b[3])
        h = y2 - y1
        w = x2 - x1
        confidence = b[4]
        confidence = float(confidence)
        student_body_rectangles.append({'x': x1, 'y': y1, 'width': w, 'height': h, 'confidence':confidence})

    for b in adult_boxes:

        x1, y1, x2, y2 = int(b[0]), int(b[1]), int(b[2]), int(b[3])
        h = y2 - y1
        w = x2 - x1
        confidence = b[4]
        confidence = float(confidence)
        adult_body_rectangles.append({'x': x1, 'y': y1, 'width': w, 'height': h, 'confidence':confidence})

    results = {'student':{'student_num':num_stu, 'student_body_rectangles':student_body_rectangles},
               'adult': {'adult_num':num_adult, 'adult_body_rectangles':adult_body_rectangles}}

    return results

def nms(dets, thresh):

    x1 = dets[:,0]
    y1 = dets[:,1]
    x2 = dets[:,2]
    y2 = dets[:,3]
    areas = (y2-y1+1) * (x2-x1+1)
    scores = dets[:,4]
    keep = []
    index = scores.argsort()[::-1]
    while index.size >0:
        i = index[0]       # every time the first is the biggst, and add it directly
        keep.append(i)


        x11 = np.maximum(x1[i], x1[index[1:]])    # calculate the points of overlap
        y11 = np.maximum(y1[i], y1[index[1:]])
        x22 = np.minimum(x2[i], x2[index[1:]])
        y22 = np.minimum(y2[i], y2[index[1:]])


        w = np.maximum(0, x22-x11+1)    # the weights of overlap
        h = np.maximum(0, y22-y11+1)    # the height of overlap

        overlaps = w*h
        #mious = overlaps / (areas[i]+areas[index[1:]] - overlaps)
        mious = overlaps / np.minimum(areas[i], areas[index[1:]])
        idx = np.where(mious<=thresh)[0]
        index = index[idx+1]   # because index start from 1

    return keep



CONFIG_FILE_PATH = os.path.join(ROOT_PATH, 'configs/cascade_rcnn/cascade_rcnn_r50_fpn_1x_student.py')
CHECK_POINT_PATH = os.path.join(ROOT_PATH, 'work_dirs/epoch_24.pth')
print(ROOT_PATH)
print(CONFIG_FILE_PATH)
print(CHECK_POINT_PATH)
# /home/diaoaijie/workspace/student/configs/cascade_rcnn/cascade_rcnn_r50_fpn_1x_student.py
# /home/diaoaijie/workspace/student/app_pack/algorithm/configs/cascade_rcnn/cascade_rcnn_r50_fpn_1x_student.py
if(os.path.exists(CONFIG_FILE_PATH)):
    print("文件存在")
else :
    print("file is not")
model = init_detector(CONFIG_FILE_PATH,CHECK_POINT_PATH,'cuda:0')


def dection_cv_image(image):

    results = inference(model,image)
    return results

def main():
    # detector = StudentNumberDetector(CHECK_POINT_PATH, CONFIG_FILE_PATH)
    # ## 接口运行示例，输入图片路径，输出检测结果dict
    # image_dir = './test_imgs/'
    # image_list = glob(os.path.join(image_dir, '*.jpg'))
    #
    # current_time = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
    # print(current_time)
    # for img_path in tqdm(image_list):
    #     image = cv2.imread(img_path)
    #     results = detector.inference(image)
    #     print(img_path)
    #     print(results)
    img_path = "R.jpeg"
    image = cv2.imread(img_path)
    print(img_path)
    print(type(image))
    print(image)
    results = dection_cv_image(image)
    print(results)
    pass


if __name__ == '__main__':
    main()
