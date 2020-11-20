#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 100

//메뉴 함수 
void menu(){
	printf("\n");
	printf("\n\t%30s", "※학생 주소록 프로그램※\n\n");
	printf("\t----------------------------------\n\n");
	printf("%20s", "\t\tmenu\n\n\n");
	printf("\t\t(1) 주소록 조회\n\n");
	printf("\t\t(2) 주소록 등록\n\n");
	printf("\t\t(3) 주소록 검색\n\n");
	printf("\t\t(4) 주소록 삭제\n\n");
	printf("\t\t(5) 주소록 종료\n\n\n\n");
	printf("\t----------------------------------\n\n");
	printf("\t실행할 버튼을 입력해주세요 : ");
}

//조회 함수
void show(){
	long sid[MAX];
	char name[MAX][10], sex[MAX], phoneNumber[MAX][14];
	int grade[MAX];
	int num;
	int i = 0;
	
	FILE *fp, *fout;
	fp = fopen("student.txt", "rt");
	
	// 데이터 조회
	do{
		fscanf(fp, "%ld %s %d %c %s", &sid[i], &name[i], &grade[i], &sex[i], &phoneNumber[i]);
		printf("\n\n %ld %s %d %c %s", sid[i], name[i], grade[i], sex[i], phoneNumber[i]);
		
		i++;
	}while(!feof(fp));
	
	//다음 메뉴로 이동 
	while (1) 
	{
		printf("\n\n\n\n(1) 메뉴\n\n(2) 등록\n\n\n입력해주세요 : ");
		scanf("%d", &num);
		
		switch (num)
		{
		case 1: 
			return;
			break;
		case 2: 
			printf("\n\n(2) 주소록 등록\n\n");
			insert();
			return;
			break;
		default:
			printf("\n\n\n잘못된 번호입니다. 다시 입력해주세요");
			break;
		}
	}
	
	return;
}

//등록 함수
void insert(){
		
		long sid;
		char name[10], sex, phoneNumber[14];
		int grade;
		FILE *fp, *fout;
		
		fout = fopen("student.txt", "a");
		
		printf("\n\n학번: "); 
		scanf("%ld", &sid);
		fflush(stdin);
		
		printf("\n이름: "); 
		scanf("%s", name);
		
		printf("\n학년: "); 
		scanf("%d", &grade);
		
		printf("\n성별(F or M) : "); 
		scanf(" %c", &sex);
		
		printf("\n전화번호(xxx-xxxx-xxx): "); 
		scanf("%s", phoneNumber);
		
		fprintf(fout, "\n%ld %s %d %c %s", sid, name, grade, sex, phoneNumber);
		printf("\n\n\n입력이 성공적으로 완료되었습니다.\n");
		printf("\n\n%ld %s %d학년 %c %s\n\n", sid, name, grade, sex, phoneNumber);
		fclose(fout);
		
		return;
} 

//검색 함수
void search(){
	
	long sid[MAX];
	char name[MAX][10], sex[MAX], phoneNumber[MAX][14];
	int grade[MAX];
	int num, inputNum;
	int i, j;
	int count = 0;
	char inputName[10];
	
	FILE *fp, *fout;
	fp = fopen("student.txt", "rt");
	
	//이름 입력 받음 
	printf("\n\n이름을 입력해주세요 : ");
	scanf("%s", inputName);
	
	//데이터 조회 
	do{
		fscanf(fp, "%ld %s %d %c %s", &sid[i], &name[i], &grade[i], &sex[i], &phoneNumber[i]);
		//printf("\n %ld %s %d %c %s", sid[i], name[i], grade[i], sex[i], phoneNumber[i]); //조회테스트
		
		i++;
	}while(!feof(fp));
	fclose(fp);
	
	printf("\n\n----------------검색결과표시----------------\n\n");
	
	//비교해서 같으면 출력
	for(j = 0; j < i; j++){
		if(strcmp(inputName, name[j]) == 0){
			printf("    %ld %s %d %c %s\n\n", sid[j], name[j], grade[j], sex[j], phoneNumber[j]);
			
			count++;	
		}
	}
	
	//다르면 "검색결과없음" 출력 
	if(count == 0){
		printf("\t\t검색결과없음\n\n");
	}
	
	printf("--------------------------------------------");
	
	//다음 메뉴로 이동
	while (1) 
	{
		printf("\n\n\n\n(1) 메뉴\n\n(2) 다시검색\n\n\n입력해주세요 : ");
		scanf("%d", &inputNum);
		fflush(stdin);
		
		switch (inputNum)
		{
		case 1: 
			return;
			break;
		case 2: 
			printf("\n\n(2) 다시검색\n\n");
			search();
			return;
			break;
		default:
			printf("\n\n\n잘못된 번호입니다. 다시 입력해주세요\n\n");
			break;
		}
	}
	
	return;
}

//삭제 함수
void del(){
	
	long sid[MAX];	//학번 
	char name[MAX][10], sex[MAX], phoneNumber[MAX][14];	//이름, 전화번호 
	int grade[MAX];	//학년 
	char inputName[10];	//입력받는 이름 
	char inputDel[1];	//삭제여부 판단 
	char y[10];	//입력받는 이름 초기화 
	int i, j;	//i : 배열 끝까지 돌리기위한 변수, j : 입력받은 값과 일치하는 배열의 값 
	int inputNum;	//다음 메뉴로 이동하기 위한 값을 입력받음
	int count = 0;	
	
	FILE *fp, *fout;
	fp = fopen("student.txt", "rt");	//파일을 읽기모드로 불러오기
	
	//데이터 조회
	do{
		//파일에 있는 데이터 출력
		fscanf(fp, "%ld %s %d %c %s", &sid[i], &name[i], &grade[i], &sex[i], &phoneNumber[i]);
		//printf("\n %ld %s %d %c %s", sid[i], name[i], grade[i], sex[i], phoneNumber[i]); //조회테스트
		
		i++;
	}while(!feof(fp));
	
	fclose(fp);	//읽기모드 종료 
	fout = fopen("student.txt", "wt");	//파일을 쓰기모드로 불러오기 
	
	printf("\n\n삭제할 학생의 이름을 입력하세요 : ");
	scanf("%s", inputName);	//삭제할 이름 입력 
	
	//입력받은 이름과 대조 
	for(j = 0; j < i; j++){
		//printf(strcmp(inputName, name[j]) == 0?"true" : "false"); //문자열 비교 테스트
		strcpy(y, inputName);	//입력받은 값을 y로 복사
		
		//입력받은 값과 일치하면 삭제 여부 판단 
		if(strcmp(inputName, name[j]) == 0){
			//입력받은 값과 일치하는 배열값이 있으면 해당 학번, 이름, 학년, 성별, 전화번호 출력 
			printf("\n\n   %ld %s %d %c %s", sid[j], name[j], grade[j], sex[j], phoneNumber[j]);
			printf("\n\n\n삭제할까요? (y/n) : ");
			//삭제여부 판단
			scanf(" %s", &inputDel);
			//printf(strcmp(inputDel, y) == 0?"true" : "false"); //문자열 비교 테스트
			//버퍼 초기화
			fflush(stdin);
			
			//입력받은 값이 'y'이면 삭제
			if(strcmp(inputDel, "y") == 0){
				//해당 배열의 삭제 문구 출력 
				printf("\n   %ld %s %d %c %s (삭제)", sid[j], name[j], grade[j], sex[j], phoneNumber[j]);
				//y의 값을 inputName으로 복사
				strcpy(inputName, y);
				//출력 후 입력받은 값과 일치하는 이름이 더 있는지 루프
				continue;
			}
		}
		strcpy(inputName, y);	//inputName에 y값을 복사
		
		//count가 0이 아니면 엔터출력
		if(count != 0){
			fprintf(fout, "\n");
		}
		//데이터 덮어씌움
		fprintf(fout, "%ld %s %d %c %s", sid[j], name[j], grade[j], sex[j], phoneNumber[j]);
		count++;	//반복문이 돌 때마다 count를 1씩 증가
	}
	fclose(fout);	//쓰기모드 종료
	
	//다음 메뉴로 이동 
	while (1) 
	{
		printf("\n\n\n\n(1) 메뉴\n\n(2) 추가삭제\n\n\n입력해주세요 : ");
		scanf("%d", &inputNum);	//입력받은 값 출력 
		fflush(stdin);	//버퍼 초기화 
		
		// 입력받은 값에 해당하는 함수실행 
		switch (inputNum)
		{
		case 1:	//메뉴이동
			return;
			break;
		case 2:	//삭제로 이동
			printf("\n\n(2) 추가삭제\n\n");
			del();
			return;
			break;
		default:	//입력받은 값이 1과 2이외일 경우 출력
			printf("\n\n\n잘못된 번호입니다. 다시 입력해주세요\n\n");
			break;
		}
	}
	return;
}

int main(int argc, char *argv[]) {
	
	int inputNumber;
	
	while (1) 
	{
		menu();
		 
		scanf("%d", &inputNumber);
		switch (inputNumber)
		{
		case 1: 
			printf("\n\n(1) 주소록 조회\n");
			show();
			break;
		case 2: 
			printf("\n\n(2) 주소록 등록\n");
			insert();
			break;
		case 3: 
			printf("\n\n(3) 주소록 검색\n");
			search();
			break;
		case 4:
			printf("\n\n(4) 주소록 삭제\n");
			del();
			break;
		case 5:
			printf("\n\n(5) 주소록 종료\n");
			return;
			break;
		default:
			printf("잘못된 번호입니다. 다시 입력해주세요");
			break;
		}
	}
	
	printf("%""--------------------------------\n");
	
}