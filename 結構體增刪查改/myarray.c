#include "myarray.h"

void init(struct Data *parr) {
	parr->pstart = NULL;
	parr->lenth = 0;
	parr->sort = 0;
}

void initWithData(struct Data *parr, datatype data) {
	parr->pstart = malloc(sizeof(data));
	parr->lenth = 1;
	*(parr->pstart) = data;
}

void initWithArray(struct Data *parr, datatype *arr, datatype data_lenth) {
	parr->pstart = malloc(sizeof(arr)*data_lenth);
	memcpy(parr->pstart, arr, sizeof(*arr)*data_lenth);
	parr->lenth = data_lenth;
	printf("%d", parr->pstart[2]);
}

void show(struct Data *parr) {
	if (parr == NULL || parr->pstart == NULL || parr->lenth == 0) {
		printf("無輸入資料...\n");
	}
	else
		for (int i = 0; i < parr->lenth; i++) {
			printf("%4d", parr->pstart[i]);
		}
}
