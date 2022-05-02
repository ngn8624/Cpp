export module swap;

export void swap(int&x, int&y)  // 노출시킬 것에만 export를 기입 // export 안붙이면 식별자 찾을 수 없습니다라고 나옴
{
	int temp = x;
	x = y;
	y = temp;
}