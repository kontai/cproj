#define _CRT_SECURE_NO_WARNINGS
#include "dri_scale.h"

#define MAXLINE 256
#define BUFFSIZE 20

/*
 *2025/05/04
 *AuTHOR:kontai
 *2025/05/15-repeat方式為使用原始座標+累加座標,origP存的是原始座標
 */

 /* G-code command list
  G84		Circle		OK
  G85		Slot		OK
  M01/M06	End of Pattern		OK
  M25		Beginning of Pattern		OK
  %			Beginning of Pattern
  M02X#Y#	Repeat Pattern Offset		OK
  M08		End of Step and Repeat		OK
  M18		Command tool tip check		OK
  M19		OK
  M97,text	Canned Text		OK
  M98,text	Canned Text		OK
  M02XYM70	Swap Axes
  M02XYM80	Mirror Image X Axis
  M02XYM90	Mirror Image Y Axis
  */
void calc_g85(char* ptr, char* g85spc, int x_offset, int y_offset, double xscale, double yscale)
{
	int g85x = 0, g85y = 0;
	int g85xsign = 0, g85ysign = 0;
	char g85xcoord[8] = { 0 }; // X徧移量座標
	char g85ycoord[8] = { 0 }; // Y徧移量座標
	sscanf(ptr, "G85X%dY%d", &g85x, &g85y);
	g85x += x_offset;
	g85y += y_offset;
	if (g85x < 0)
		g85xsign = 1;
	if (g85y < 0)
		g85ysign = 1;
	// 計算x與y座標的長度,四捨入後的長度
//xnum = abs(round(xnum * xscale));

	g85x = abs(round(g85x * xscale));
	g85y = abs(round(g85y * yscale));
	if (g85xsign == 1)
	{
		sprintf(g85xcoord, "-%06d", g85x);
	}
	else
	{
		sprintf(g85xcoord, "%06d", g85x);
	}
	if (g85ysign == 1)
	{
		sprintf(g85ycoord, "-%06d", g85y);
	}
	else
	{
		sprintf(g85ycoord, "%06d", g85y);
	}
	sprintf(g85spc, "G85X%sY%s", g85xcoord, g85ycoord);
}

void calc_offset(POINT** origP, int* origSize, int* origCap, int isMod, int* modeCount, int* mode, char* xOffsetSum, char* yOffsetSum,
	char* offX, char* offY, FILE* fout, double xscale, double yscale)
{
	int x_coord = 0, y_coord = 0;	// x,y座標
	int x_offset = 0, y_offset = 0; // x,y偏移量
	int basex = 0, basey = 0;		// 基準座標
	int xsign = 0, ysign = 0;
	int xnum = 0, ynum = 0; // x,y座標數值
	int xoffsum = 0, yoffsum = 0; // x,y偏移量數值


	sscanf(offX, "%d", &x_offset);		 // 讀取x偏移量
	sscanf(offY, "%d", &y_offset);		 // 讀取y偏移量

	if (isMod == 1)
	{
		//判斷是否為鏡像模式

		sscanf(xOffsetSum, "%d", &xoffsum); // 讀取x偏移量
		sscanf(yOffsetSum, "%d", &yoffsum);	// 讀取y偏移量
		x_offset += xoffsum;	//將目前x偏移量加到總偏移量
		y_offset += yoffsum;	//將目前x偏移量加到總偏移量
		int x_offset_sum = abs(x_offset);
		int y_offset_sum = abs(y_offset);
		int x_offset_sign = x_offset < 0 ? 1 : 0;
		int y_offset_sign = y_offset < 0 ? 1 : 0;

		if (x_offset_sign == 1)
		{
			sprintf(xOffsetSum, "-%06d", x_offset_sum); // 儲存x偏移量
		}
		else
		{
			sprintf(xOffsetSum, "%06d", x_offset_sum); // 儲存x偏移量
		}

		if (y_offset_sign == 1)
		{
			sprintf(yOffsetSum, "-%06d", y_offset_sum); // 儲存y偏移量
		}
		else
		{
			sprintf(yOffsetSum, "%06d", y_offset_sum); // 儲存y偏移量
		}
	}

	for (int i = 0; i < *origSize; i++)
	{
		char xcoord[8] = { 0 };  // X徧移量座標
		char ycoord[8] = { 0 };  // Y徧移量座標
		char g85spc[24] = { 0 }; // G85指令
		char* ptr = NULL;	   // G85指令的指標
		int isG85 = 0;
		sscanf((*origP)[i].x, "%d", &basex); // 讀取基準x座標
		sscanf((*origP)[i].y, "%d", &basey); // 讀取基準y座標
		// origP[i].spc 是否為G85指令
		if ((ptr = strstr((*origP)[i].spc, "G85")) != NULL || (ptr = strstr((*origP)[i].spc, "g85")) != NULL)
		{
			isG85 = 1;
			calc_g85(ptr, g85spc, x_offset, y_offset, xscale, yscale);
		}
		x_coord = basex + x_offset;	 // 計算徧移x座標
		y_coord = basey + y_offset;	 // 計算徧姼y座標
		xsign = x_coord < 0 ? 1 : 0; // x座標符號
		ysign = y_coord < 0 ? 1 : 0; // y座標符號
		xnum = abs(x_coord);
		ynum = abs(y_coord);
		if (xsign == 1)
		{
			sprintf(xcoord, "-%06d", xnum);
		}
		else
		{
			sprintf(xcoord, "%06d", xnum);
		}

		if (ysign == 1)
		{
			sprintf(ycoord, "-%06d", ynum);
		}
		else
		{
			sprintf(ycoord, "%06d", ynum);
		}

		// 儲存徧姼座標offsetPoint
		if (isG85 == 1)
		{
			calc_point(fout, xscale, yscale, xcoord, ycoord, g85spc);
		}
		else
		{
			calc_point(fout, xscale, yscale, xcoord, ycoord, (*origP)[i].spc);
		}
	}
}

//TODO: 計算G85指令的座標補償
void calc_point(FILE* fout, double xscale, double yscale, char* x, char* y, char* spc)
{
	int xsign = 0;
	int ysign = 0;
	char xcoord[8] = { 0 }; // X徧移量座標
	char ycoord[8] = { 0 }; // Y徧移量座標
	char g85spc[24] = { 0 }; // G85指令
	char* ptr = NULL;	   // G85指令的指標
	int isG85 = 0;
	xsign = (*x == '-' ? 1 : 0);
	ysign = (*y == '-' ? 1 : 0);
	int xnum = 0, ynum = 0;
	sscanf(x + xsign, "%d", &xnum);
	sscanf(y + ysign, "%d", &ynum);

	xnum = abs(round(xnum * xscale));
	ynum = abs(round(ynum * yscale));

	if (xsign == 1)
	{
		sprintf(xcoord, "-%06d", xnum);
	}
	else
	{
		sprintf(xcoord, "%06d", xnum);
	}

	if (ysign == 1)
	{
		sprintf(ycoord, "-%06d", ynum);
	}
	else
	{
		sprintf(ycoord, "%06d", ynum);
	}

	// 計算G85指令的座標補償
	if ((ptr = strstr(spc, "G85")) != NULL || (ptr = strstr(spc, "g85")) != NULL)
	{
		isG85 = 1;
		calc_g85(ptr, g85spc, 0, 0, xscale, yscale);
	}

	if (isG85 == 1)
	{
		fprintf(fout, "X%sY%s%s\n", xcoord, ycoord, g85spc);
	}
	else
	{
		fprintf(fout, "X%sY%s%s\n", xcoord, ycoord, spc);
	}
}

void parse_point(char* line, char* x, char* y, char* spc)
{
	/*
	 * parameters:
	 * line: 讀取的行
	 * x: x座標
	 * y: y座標
	 * spc: 其他參數
	 */
	int xsign = 0;			  // x 正/負號
	int ysign = 0;			  // y 正/負號
	int digit = 6;			  // 預設座標精度
	int x_loc = 0, y_loc = 0; // 暫存x,y座標數值
	int len_x = 0, len_y = 0; // x,y字串長度(包含符號,作補0用)
	int x_cnt = 0, y_cnt = 0; // x,y字串長度(不包含符號,作補0用)

	// 是否是G84指令(擴孔)
	int isG84 = 0;
	// 是否是G85指令(槽孔)
	int isG85 = 0;
	//是否為M70(旋轉)、M80(x-mirror)、M90模式(y-mirror)
	int isMode = 0;
	//指針(尋找G84/G85/M70/M80/M90)
	char* ptr = NULL;

	// Initialize x and y to empty strings for safety
	x[0] = '\0';
	y[0] = '\0';

	//特
	if ((ptr = strstr(line, "G84")) != NULL || (ptr = strstr(line, "g84")) != NULL)
	{
		isG84 = 1;
	}
	else if ((ptr = strstr(line, "G85")) != NULL || (ptr = strstr(line, "g85")) != NULL)
	{
		isG85 = 1;
	}
	else if ((ptr = strstr(line, "M70")) != NULL || (ptr = strstr(line, "M80")) != NULL || (ptr = strstr(line, "M90")) != NULL)
	{
		isMode = 1;
	}

	if (sscanf(line, "X%dY%d", &x_loc, &y_loc) == 2)
	{
		//判斷x,y座標是否為負數
		xsign = (x_loc < 0) ? 1 : 0;
		ysign = (y_loc < 0) ? 1 : 0;

		// 計算x與y字串的長度
		len_x = strlen(line) - strlen(strchr(line, 'Y')) - 1 + xsign; // x座標長度
		if (isG84 == 1 || isG85 == 1 || isMode == 1)
		{
			len_y = strlen(strchr(line, 'Y')) - strlen(ptr) - 1 + ysign; // y座標長度
			strcpy(spc, ptr);											 // 複製其他參數)
		}
		else
		{
			len_y = strlen(strchr(line, 'Y')) - 1 + ysign; // y座標長度
		}

		// Ensure we don't overflow the destination buffers (max size 7 chars + null terminator = 8)
		if (len_x >= 7)
			len_x = 7;
		if (len_y >= 7)
			len_y = 7;

		strncpy(x, line + 1, len_x);			 // 複製x座標
		strncpy(y, line + 1 + len_x + 1, len_y); // 複製y座標

		//如果x,y座標長度小於6，則補0
		x_cnt = len_x - xsign;
		y_cnt = len_y - ysign;

		if (x_cnt < digit)
		{
			for (int i = 0; i < digit - x_cnt; i++)
			{
				x[x_cnt + i] = '0'; // 補0
			}
		}
		if (y_cnt < digit)
		{
			for (int i = 0; i < digit - y_cnt; i++)
			{
				y[y_cnt + i] = '0'; // 補0
			}
		}

		x[digit + xsign] = '\0'; // 結尾
		y[digit + ysign] = '\0'; // 結尾
	}
	else if (line[0] == 'X')
	{
		if (isMode == 1) {
			strcpy(y, "000000");
		}
		else {
			// r座標為上一個座標
			strcpy(y, "prev");
		}

		// 成功解析X座標
		sscanf(line, "X%d", &x_loc);
		if (x_loc < 0)
			xsign = 1;
		// 計算x字串的長度
		if (isG84 == 1 || isG85 == 1 || isMode == 1)
		{
			len_x = strlen(line) - strlen(ptr) - 1 + xsign; // y座標長度
			strcpy(spc, ptr);								// 複製其他參數)
		}
		else
		{
			len_x = strlen(line) - 1 + xsign; // x座標長度
		}

		// Ensure we don't overflow the destination buffers (max size 7 chars + null terminator = 8)
		if (len_x >= 7)
			len_x = 7;

		strncpy(x, line + 1, len_x); // 複製x座標
		x_cnt = len_x - xsign;
		if (x_cnt < digit)
		{
			for (int i = 0; i < digit - x_cnt; i++)
			{
				x[x_cnt + i] = '0'; // 補0
			}
		}
	}
	else if (line[0] == 'Y')
	{
		if (isMode == 1) {
			strcpy(x, "000000");
		}
		else {
			// r座標為上一個座標
			strcpy(x, "prev");
		}

		// 成功解析Y座標
		sscanf(line, "Y%d", &y_loc);
		if (y_loc < 0)
			ysign = 1;

		// 計算y字串的長度
		if (isG84 == 1 || isG85 == 1 || isMode == 1)
		{
			len_y = strlen(line) - strlen(ptr) - 1 + ysign; // y座標長度
			strcpy(spc, ptr);								// 複製其他參數)
		}
		else
		{
			len_y = strlen(line) - 1 + ysign; // y座標長度
		}

		// Ensure we don't overflow the destination buffers (max size 7 chars + null terminator = 8)
		if (len_y >= 7)
			len_y = 7;

		strncpy(y, line + 1, len_y); // 複製y座標)
		y_cnt = len_y - ysign;

		if (y_cnt < digit)
		{
			for (int i = 0; i < digit - y_cnt; i++)
			{
				y[y_cnt + i] = '0'; // 補0
			}
		}
	}
	// else
	//{
	//	fprintf(stderr, "Error parsing point: %s\n", line);
	//	exit(EXIT_FAILURE);
	// }
}
void add_point(POINT** array, int* size, int* cap, char* x, char* y, char* spc)
{
	// 增加座標
	if (*size >= *cap)
	{
		*cap *= 2;
		*array = (POINT*)realloc(*array, sizeof(POINT) * (*cap));
		if (!*array)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
	}

	// 修正錯誤的地方，使用正確的結構成員訪問方式
	if (strcmp(x, "prev") == 0)
		strncpy((*array)[*size].x, (*array)[*size - 1].x, sizeof((*array)[*size].x));
	else
		strncpy((*array)[*size].x, x, sizeof((*array)[*size].x));

	if (strcmp(y, "prev") == 0)
		strncpy((*array)[*size].y, (*array)[*size - 1].y, sizeof((*array)[*size].y));
	else
		strncpy((*array)[*size].y, y, sizeof((*array)[*size].y));

	if (strlen(spc) > 0)
	{
		if (strstr(spc, "G85") != NULL || strstr(spc, "g85") != NULL)
		{
			char _x[8] = { 0 }, _y[8] = { 0 }, _spc[24] = { 0 };
			parse_point(spc + 3, _x, _y, _spc);
			if (strcmp(_x, "prev") == 0)
			{
				sprintf(_spc, "G85X%sY%s", x, _y);
			}
			else if (strcmp(_y, "prev") == 0)
			{
				sprintf(_spc, "G85X%sY%s", _x, y);
			}
			else {
				sprintf(_spc, "G85X%sY%s", _x, _y);
			}
			strcpy(spc, _spc);
			strncpy((*array)[*size].spc, _spc, sizeof((*array)[*size].spc));
		}
		else
		{
			strncpy((*array)[*size].spc, spc, sizeof((*array)[*size].spc));
		}
	}
	else
	{
		strcpy((*array)[*size].spc, "");
	}

	(*size)++;
}

void resest_point(POINT** array, int* size, int* cap)
{
	// 重設座標陣列
	if (*array)
	{
		free(*array);
		*array = NULL;
	}
	*size = 0;
	*cap = BUFFSIZE;
	*array = (POINT*)malloc(sizeof(POINT) * (*cap));
	if (!*array)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
}

void read_file()
{
	// read file
	FILE* fp = NULL;
	fp = fopen("D:/Test/backdrill//lce084.drl", "r");
	if (!fp)
	{
		perror("input File open error");
		exit(EXIT_FAILURE);
	}

	FILE* fp2 = NULL;
	fp2 = fopen("D:/Test/backdrill/lce084.out", "w");
	if (!fp2)
	{
		perror("output File open error");
		fclose(fp);
		exit(EXIT_FAILURE);
	}

	POINT* orgPoint = NULL;
	POINT* offsetPoint = NULL;
	int baseSize = 0, offsetSize = 0,			  // 已存座標數量
		baseCap = BUFFSIZE, offsetCap = BUFFSIZE; // 容量大小
	char line[MAXLINE] = { 0 };					  // 讀取輸入緩存
	int inTsection = 0;							  // 是否在T-Code區段
	int offsetSection = 0;						  // 是否在Offset區段(連片)
	int isM01mode = 0;							  // 是否在M01模式(連片)
	int isM98mode = 0;							  // 是否在M98模式
	double xscale = 1.000, yscale = 1.000;			  // 縮放比例
	char xOffsetSum[8] = { 0 }, yOffsetSum[8] = { 0 }; // 總徧移量
	int isMode = 0;		//Mirror,Rotate mode
	int mode_Count = 0;	//mode計數
	int mode = 0;

	// 初始化
	resest_point(&orgPoint, &baseSize, &baseCap);

	while ((fgets(line, sizeof(line), fp)) != NULL)
	{
		line[strcspn(line, "\r\n")] = 0; // 去除換行符號

		////DEBUG
		//if (strcmp(line, "T01") == 0) {
		//	system("pause");
		//}

		if (strcspn(line, "T") == 0 && strlen(line) == 3)
		{
			fprintf(fp2, "%s\n", line); // 打印T-Code

			//重設
			isM98mode = 0;

			isMode = 0;

			// 新區塊開始
			resest_point(&orgPoint, &baseSize, &baseCap);
			resest_point(&offsetPoint, &offsetSize, &offsetCap);

			static const char zero[8] = { 0 };  // 靜態全零數組
			if (memcmp(xOffsetSum, zero, 8) != 0)	// 直接比對記憶體
			{
				// 如果xOffsetSum不為0，則清空
				memset(xOffsetSum, 0, sizeof(xOffsetSum));
			}
			if (memicmp(yOffsetSum, zero, 8) != 0)	// 直接比對記憶體
			{
				// 如果yOffsetSum不為0，則清空
				memset(yOffsetSum, 0, sizeof(yOffsetSum));
			}

			inTsection = 1;
			offsetSection = 0;
			continue;
		}
		if (strstr(line, "M98") != NULL || strstr(line, "M97") != NULL)
		{
			// 打印M98指令,inTsection=0,座標不會被記錄、補償
			fprintf(fp2, "%s\n", line);
			isM98mode = 1;
			inTsection = 0;
			offsetSection = 0;
			continue;
		}

		if (strcspn(line, "M18") == 0 && line[1] == '1') {
			fprintf(fp2, "%s\n", line); // 打印M18指令
			continue;
		}
		if (strcmp(line, "M19") == 0) {
			fprintf(fp2, "%s\n", line); // 打印M19指令
			continue;
		}

		// M25-M01區段=repeat and drop
		//pattern begin
		if (strcmp(line, "M25") == 0)
		{
			isM01mode = 1;
			inTsection = 1;
			offsetSection = 0;

			continue;
		}

		if (inTsection == 0)
		{
			fprintf(fp2, "%s\n", line);
			continue;
		}

		//end of pattern
		if (strcmp(line, "M01") == 0)
		{
			isM01mode = 0;
			continue;
		}

		//end of repeat
		if (strcmp(line, "M02") == 0 || strcmp(line, "M08") == 0)
		{
			isM01mode = 0;
			if (strcmp(line, "M08") == 0)
			{
				resest_point(&orgPoint, &baseSize, &baseCap);
				inTsection = 0;
				isMode = 0;
				mode_Count = 0;
				mode = 0;
			}
			continue;
		}

		if (strcspn(line, "M02") == 0 && strlen(line) > 4)
		{
			offsetSection = 1;
			isM01mode = 0;
		}
		char x[8] = { 0 }, y[8] = { 0 };
		char spc[24] = { 0 };
		if (offsetSection == 0)
		{
			parse_point(line, x, y, spc);
		}
		if (isM01mode == 1 && offsetSection == 0)
		{
			//in pattern
			// 記錄厡始座標
			add_point(&orgPoint, &baseSize, &baseCap, x, y, spc);
			// 計算+輸出座標
			calc_point(fp2, xscale, yscale, x, y, spc);
		}
		else if (offsetSection == 1)
		{
			// end of pattern,start repeat
			// 1.offsetPoint=basePoint+offset
			// 1-1.獲取M02座標
			parse_point(line + 3, x, y, spc);
			// 計算連片座標並取代basePoint
			if (baseSize <= 0)
			{
				MessageBoxA(0, "Error", "No base point");
				exit(1);
			}
			else
			{
				if (strstr(spc, "M70") != NULL || strstr(spc, "M80") != NULL || strstr(spc, "M90") != NULL)
				{
					isMode = 1;
					mode_Count = 1;
					if (strstr(spc, "M70") != NULL)
						mode += M70;
					if (strstr(spc, "M80") != NULL)
						mode += M80;
					if (strstr(spc, "M90") != NULL)
						mode += M90;
				}
				// 計算徧移座標

				calc_offset(&orgPoint, &baseSize, &baseCap, isMode, &mode_Count, &mode, xOffsetSum, yOffsetSum, x, y,
					fp2, xscale, yscale);
			}
		}

		// 2.replace basePoint with offsetPoint
		else
		{
			// calc  and print
			calc_point(fp2, xscale, yscale, x, y, spc);
		}

		if (strcmp(line, "M30") == 0)
		{
			fprintf(fp2, "%s\n", line);
			inTsection = 0;
			break; // 程式結束
		}
	}
	if (orgPoint != NULL)
	{
		free(orgPoint);
		orgPoint = NULL;
	}

	fclose(fp);
	fclose(fp2);
}

int main()
{
	read_file();
	return EXIT_SUCCESS;
}