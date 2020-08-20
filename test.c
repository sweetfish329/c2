#include<stdio.h>
#include<string.h>
#define N 100

int main(void) {
	int number[N], score[N][3], i, j, subject, max = 0, min = 0, sortarr[N], total[N];
	char name[N][50], mode,srcname[50];

	for (i = 0; i < N; i++) {
		printf("学生番号を入力してください：");
		rewind(stdin);
		scanf("%d", &number[i]);
		if (number[i] == 99999) {
			break;
		}
		printf("名前を入力してください：");
		rewind(stdin);
		scanf("%s", &name[i]);
		printf("英語、数学、情報の特典を入力してください：");
		rewind(stdin);
		scanf("%d%d%d", &score[i][0], &score[i][1], &score[i][2]);
		max++;
	}
	for (j = 0; j <= max; j++) {
		if (number[j] != 99999) {

			printf("学生番号:%d 名前:%s\t英語:%d点 数学%d点 情報%d点\n", number[j], name[j], score[j][0], score[j][1], score[j][2]);

		}

	}

	do {
		printf("b,Bc,C,e,E,m,M,i,I,t,T,s,Sのどれか一文字を入力してください。\n");
		rewind(stdin);
		scanf("%c", &mode);
		subject = 5;
		switch (mode) {
		case 'b':;
		case 'B':printf("学生番号を入力してください：");
			scanf("%d", &j);
			for(i=0;1;i++) {
			if (number[i] == j) {
				break;
				}
			}
			printf("名前:%s\t英語:%d点 数学%d点 情報%d点\n", name[i], score[i][0], score[i][1], score[i][2]);
			break;
		case 'c':;
		case 'C':printf("名前を入力してください：");
			scanf("%s", &srcname);
			for (i = 0; 1;i++) {
				if (strcmp(name[i], srcname)==0) {
					break;
				}
			}
			printf("学生番号%d \t英語:%d点 数学%d点 情報%d点\n", number[i], score[i][0], score[i][1], score[i][2]);
			break;
		case'e':;
		case 'E':
			subject = 0;
			break;
		case'm':;
		case 'M':
			subject = 1;
			break;
		case'i':;
		case 'I':
			subject = 2;
			break;
		case't':;
		case 'T':
			for (i = 0; i < max; i++) {
				total[i] = score[i][0] + score[i][1] + score[i][2];
			}
			subject = 3;
			break;
		default: break;
		}

		if (subject <= 2 && subject >= 0) {
			for (i = 0; i < max; i++) {
				sortarr[i] = 0;
				for (j = i+1; j < max; j++) {
					if (i == 0) {
						if (score[j][subject] > score[sortarr[i]][subject]) {
							sortarr[i] = j;
						}
					}
					else {
						if (score[j][subject] > score[sortarr[i]][subject] && score[j][subject] < score[sortarr[i - 1]][subject]) {
							sortarr[i] = j;
						}
					}
				}
			}
			for (i = 0; i < max; i++) {
				printf("学生番号：%d 名前:%s\t得点：%d\n", number[sortarr[i]], name[sortarr[i]], score[sortarr[i]][subject]);
			}
		}
		else if(subject==3) {
			for (i = 0; i < max; i++) {
				sortarr[i] = 0;
				for (j = i+1; j < max; j++) {
					if (i == 0) {
						if (total[j] > total[sortarr[i]]) {
							sortarr[i] = j;
						}
					}
					else {
						if (total[j] > total[sortarr[i]] /*&&total[j] < total[sortarr[i - 1]]*/) {
							sortarr[i] = j;
						}
					}
				}
			}
			for (i = 0; i < max; i++) {
				printf("学生番号：%d 名前:%s\t得点：%d\n", number[sortarr[i]], name[sortarr[i]], total[sortarr[i]]);
			}
		}
	



		rewind(stdin);

	} while (mode != 's'&&mode != 'S');
}
