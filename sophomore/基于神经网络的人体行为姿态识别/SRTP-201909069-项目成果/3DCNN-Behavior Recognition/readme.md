*����3D������������Ϊ��̬ʶ��
����ϵͳ��win10/ubuntu16.04���޸Ĵ���·����ʽ���ã�
�Կ��汾��GTX-1060
����Ҫ���谲װtensorflow-gpu��kears��
ʵ�����ݼ���UCF-101���ݼ�

*����ִ��ָ��

**���ݴ���
1. ��������UCF-101��Ϊ��̬���ݼ�����ѹ������ڳ����ļ�dataĿ¼��
2. ����dataĿ¼�µ�python�ļ�move_and_devide.py����UCF-101�ļ����е����ݰ���datasetlist�ļ������������ƶ���train_dataset��test_dataset�ļ����У��Թ����ڵĲ��Ժ�ѵ������
3. ����dataĿ¼�µ�python�ļ�extract_to_picture.py���������train_dataset��test_dataset��*.avi��Ƶ����ÿ����Ƶ��ȡΪ�������ȵ�2DͼƬ*.jpg

**ģ��ѵ��
������Ŀ¼�µ�python�ļ�train.py��ѵ��ģ�Ͳ�������dataĿ¼�µ�checkpoint�ļ����У���ʽΪ*.hdf5���������ѵ��-epoch������ǰepochģ��������һepoch����ѵ������ģ�ͱ��棩

**�������
������Ŀ¼�µ�python�ļ�test.py������data/testĿ¼���漴ѡȡ5�����ݽ��в���

**׼ȷ�ʼ���
������Ŀ¼�µ�python�ļ�calculation_accuracy.py���Ὣdata/testĿ¼�µ�������Ƶ���в��ԣ�������ģ��׼ȷ��