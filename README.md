# Body_Students_Detection Based on MMdetection


## Requirements

- mmdetection(环境配置参考：https://mmdetection.readthedocs.io/en/latest/install.html#install-mmdetection)

- 或者按照下述步骤进行安装

```

1.创建与激活conda虚拟环境
  conda create -n open-mmlab python=3.7 -y
  conda activate open-mmlab
2.安装pytorch，选择与cuda版本一致的cudatoolkit
	conda install pytorch cudatoolkit=10.1 torchvision 
3.安装其他依赖库	
  pip install mvcv==0.6.2
  pip install -r requirements/build.txt
  pip install -v -e .
  pip install pycocotools
```

切换torch 版本，torch运行 报 
ImportError: libtorch_cpu.so: cannot open shared object file: No such file or directory
解决  删除之前的build 重新建  
rm -r build
python setup.py develop
