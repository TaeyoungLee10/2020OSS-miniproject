//mini_project
//mamager.c
#include "manager.h"

void listproduct(PRODUCT* p, int count){
	printf("\n*************제품 목록*************\n");
	printf("번호 제품이름  중량  가격   표준가격    평점\n");
	printf("==========================================\n");
	for(int i=0;i<count;i++){
	if(p[i].price==-1) continue;
	printf("%3d ", i+1);
	readproduct(p[i]);
	}

}

int select_product_no(PRODUCT *p, int count){
	int no;
	listproduct(p, count);
	printf("\n=>원하는 번호는? (취소: 0) ");
	scanf("%d", &no);
	return no;
}

void searchproduct (PRODUCT *p, int count){
	int search_type;
	int i;	//반복을 위한 변수
	int search_check=0;	//계속 0이라면 아무것도 검색결과가 없다는 뜻
	printf("\n사용한 가능한 검색기능:\n");
	printf("1. 상품 이름\n");	
	printf("2. 상품 금액\n");	
	printf("3. 상품 평점\n\n");
	
	printf("=> 원하는 검색방법은? (취소: 0) ");
	scanf("%d", &search_type);
}


