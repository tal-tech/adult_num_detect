dataset_type = 'CocoDataset'
data_root = '/share/chenbo/Dataset/Adullt_children/Dataset/'
classes = ('student', 'adult')

img_norm_cfg = dict(
    mean=[123.675, 116.28, 103.53], std=[58.395, 57.12, 57.375], to_rgb=True)
train_pipeline = [
    dict(type='LoadImageFromFile'),
    dict(type='LoadAnnotations', with_bbox=True),
    dict(type='Resize', img_scale=[(1333, 640), (1333, 960)], keep_ratio=True),
    dict(type='RandomFlip', flip_ratio=0.5),
    dict(type='Normalize', **img_norm_cfg),
    dict(type='Pad', size_divisor=32),
    dict(type='DefaultFormatBundle'),
    dict(type='Collect', keys=['img', 'gt_bboxes', 'gt_labels']),
]
test_pipeline = [
    dict(type='LoadImageFromFile'),
    dict(
        type='MultiScaleFlipAug',
        img_scale=(1333, 800),
        flip=False,
        transforms=[
            dict(type='Resize', keep_ratio=True),
            dict(type='RandomFlip'),
            dict(type='Normalize', **img_norm_cfg),
            dict(type='Pad', size_divisor=32),
            dict(type='ImageToTensor', keys=['img']),
            dict(type='Collect', keys=['img']),
        ])
]
data = dict(
    samples_per_gpu=2, # batch size:samples_per_gpu * num_gpus
    workers_per_gpu=2, 

    train=[dict(
        type=dataset_type,
        classes=classes,
        ann_file=data_root + 'annotations/train_data_0706.json',
        img_prefix=data_root + 'imgs/0706_train',
        pipeline=train_pipeline),
        dict(
        type=dataset_type,
        classes=classes,
        ann_file=data_root + 'annotations/train_data_0717.json',
        img_prefix='/share/chenbo/Dataset/Adullt_children/frames/0714_shuangshi_train_model_selection',
        pipeline=train_pipeline)],

    val=dict(
        type=dataset_type,
        classes=classes,
        ann_file=data_root + 'annotations/test_data_0713.json',
        # img_prefix=data_root + 'imgs/0706_val',
        img_prefix='/share/chenbo/Dataset/Adullt_children/frames/0707_shuangshi_test_frames_new',
        pipeline=test_pipeline),
    test=dict(
        type=dataset_type,
        classes=classes,
        ann_file=data_root + 'annotations/val_data_0706.json',
        # img_prefix=data_root + 'imgs/0706_val',
        img_prefix='/share/chenbo/Dataset/Adullt_children/frames/0707_shuangshi_test_frames_new',
        pipeline=test_pipeline))
evaluation = dict(interval=5, metric='bbox')
