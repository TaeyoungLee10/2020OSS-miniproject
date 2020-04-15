//mini_project
//manager.h
//loadfile function added
//savefile function added
//search_product function added
#include <stdio.h>
#include <string.h>
#include "product.h"

void listproduct(PRODUCT* p, int count);    //제품 전체 목록 조회
int select_product_no(PRODUCT* p, int count);   //제품 번호 선택
int loadfile(PRODUCT* p);   //파일 불러오기
void savefile(PRODUCT* p, int count);   //파일 저장하기
void searchproduct(PRODUCT* p, int count);   //제품 검색
