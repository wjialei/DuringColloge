/*

��2��֤���⡣
��a��֤������������������ģ���ôQuickSort�㷨��ҪO��n^2����ʱ�䡣
��b��֤��QuickSort�������µ�ʱ�临�Ӷ���O��n^2����
��c��QuickSort����ΪʲôҪ��list[left]<=list[right+1]��仰��

��a�����������������Ѿ���˳����i��ÿ��������ͣ�٣�������ʱ��Ϊÿ��ѭ������n��ѭ��������ʱ�临�Ӷ�ΪO��n*n��;����ǡ�ɵ�����j��ÿ����ͣ�٣���������ơ�
��b��Tworst(n) <= cn + Tworst(n-1)
			 <= cn + c(n-1)+Tworst(n-2)
			  ��
			 <= (c1+c2+��+cn) + Tworst(0) = cn(n+1)/2+d = O(n^2).
��c��������Ϊ����Ϊ���������Ǵ�i��LEFT�˷�����ѡ�������j�ˣ����Լ���list[left]<=list[right+1]�ǲ�����Ϻ�������
��5�����������ǲ��ȶ��ġ�����һ�����ӣ����йؼ�����ͬ�ļ�¼�Ļ���˳������������˱仯��
	��: ������{9A��8��7��6��5��4��3��9B��1}ʱ�����ӦΪ{1��3��4��5��6��7��8��9B��9A}��	
		��Ϊ����9A��9Bǰ�棬�����������9B��9Aǰ�棬���Կ��������ǲ��ȶ��ġ�

*/



void main()
{
	while (1);
}