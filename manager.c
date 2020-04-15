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

int select_product_no(PRODUCT *p, int count){	//데이터를 수정하고 삭제할 때 사용
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

	if(search_type==1){
	char searchname[20];	//검색할 이름
	printf("검색할 상품명: ");
	scanf("%s", searchname);
	printf("\n*************제품 목록*************\n");
	printf("번호 제품이름  중량  가격   표준가격    평점\n");
	printf("==========================================\n");
		for(i=0;i<count;i++){
			if(strstr(p[i].name, searchname)){
				printf("%3d ", i+1);
				readproduct(p[i]);
				search_check++;
			}
		}	

	}
	else if(search_type==2){
	int searchprice;	//검색할 금액
	printf("검색할 상품 금액: ");
	scanf("%d", &searchprice);
	printf("\n*************제품 목록*************\n");
	printf("번호 제품이름  중량  가격   표준가격    평점\n");
	printf("==========================================\n");
		for(i=0;i<count;i++){
			if(p[i].price==searchprice){
				printf("%3d ", i+1);
				readproduct(p[i]);
				search_check++;
			}
		}	

	}
	else if(search_type==3){
	int searchrate;	//검색할 평점
	printf("검색할 상품 평점: ");
	scanf("%d", &searchrate);
	printf("\n*************제품 목록*************\n");
	printf("번호 제품이름  중량  가격   표준가격    평점\n");
	printf("==========================================\n");
		for(i=0;i<count;i++){
			if(p[i].rate_score==searchrate){
				printf("%3d ", i+1);
				readproduct(p[i]);
				search_check++;
			}
		}	
	}
	else if(search_type==0){
		printf("=> 취소됨!\n");
		return;
	}
	
	if(search_check==0)
		printf("검색 결과 없음\n");
}


int loadfile(PRODUCT* p){
	int count=0;
	FILE *fp;
	fp= fopen("product.txt", "rt");

	if(fp==NULL){
		printf("=> 파일 없음\n");
		return 0;
	}
	else{
		for(;;count++){
			fscanf(fp, "%s %d %d %d", p[count].name, &p[count].weight, &p[count].price, &p[count].rate_score);
			if(feof(fp)) break;
		}
		for(int i=0;i<count;i++)
			p[i].std_price=((p[i].price / p[i].weight)) *10;	
	}
	
	
	fclose(fp);
	printf("=>파일 로딩됨!\n");
	return count;
}

void savefile(PRODUCT* p, int count){
	FILE* fp;
	fp=fopen("product.txt", "wt");
	for(int i=0;i<count;i++){
	fprintf(fp, "%s %d %d %d\n", p[i].name, p[i].weight, p[i].price, p[i].rate_score);
	}
	fclose(fp);
	printf("=> 저장됨!\n");
}
