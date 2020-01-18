*基于3D卷积神经网络的行为姿态识别
操作系统：win10/ubuntu16.04（修改代码路径格式可用）
显卡版本：GTX-1060
环境要求：需安装tensorflow-gpu，kears库
实验数据集：UCF-101数据集

*程序执行指南

**数据处理
1. 网络下载UCF-101行为姿态数据集，解压后放置于程序文件data目录下
2. 运行data目录下的python文件move_and_devide.py，将UCF-101文件夹中的数据按照datasetlist文件内索引分类移动至train_dataset和test_dataset文件夹中，以供后期的测试和训练操作
3. 运行data目录下的python文件extract_to_picture.py，逐个处理train_dataset和test_dataset中*.avi视频，将每个视频提取为数量不等的2D图片*.jpg

**模型训练
运行主目录下的python文件train.py，训练模型并保存于data目录下的checkpoint文件夹中，格式为*.hdf5（采用逐代训练-epoch，若当前epoch模型优于上一epoch，则将训练所的模型保存）

**结果测试
运行主目录下的python文件test.py，可在data/test目录下随即选取5个数据进行测试

**准确率计算
运行主目录下的python文件calculation_accuracy.py，会将data/test目录下的所有视频进行测试，并计算模型准确率