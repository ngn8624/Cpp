export module swap;

export void swap(int&x, int&y)  // �����ų �Ϳ��� export�� ���� // export �Ⱥ��̸� �ĺ��� ã�� �� �����ϴٶ�� ����
{
	int temp = x;
	x = y;
	y = temp;
}