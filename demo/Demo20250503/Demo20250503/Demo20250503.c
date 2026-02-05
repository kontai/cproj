#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
typedef struct {
	int x;
	int y;
} Point;

int parse_coordinate(const char* line, int* x, int* y) {
	return sscanf(line, "X%dY%d", x, y) == 2;
}

void print_coord(FILE* out, char axis, int val) {
	char sign = (val < 0) ? '-' : '\0';
	int absval = abs(val);
	int digits = 0, tmp = absval;

	while (tmp > 0) {
		tmp /= 10;
		digits++;
	}
	if (digits == 0) digits = 1;

	int zeros = 6 - digits;
	if (zeros < 0) zeros = 0;

	fprintf(out, "%c", axis);
	if (sign) fprintf(out, "%c", sign);
	fprintf(out, "%d", absval);
	for (int i = 0; i < zeros; i++) {
		fputc('0', out);
	}
}

void print_point(FILE* out, Point p) {
	print_coord(out, 'X', p.x);
	print_coord(out, 'Y', p.y);
	fputc('\n', out);
}

Point* add_point(Point* array, int* size, int* capacity, Point p) {
	if (*size >= *capacity) {
		*capacity *= 2;
		array = realloc(array, (*capacity) * sizeof(Point));
		if (!array) {
			fprintf(stderr, "Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
	}
	array[(*size)++] = p;
	return array;
}

void reset_points(Point** points, int* size, int* cap) {
	*size = 0;
	if (*points == NULL) {
		*cap = 10;
		*points = malloc(*cap * sizeof(Point));
	}
}

int main() {
	FILE* fp = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");
	if (!fp || !fout) {
		perror("File error");
		return 1;
	}

	char line[256];
	Point* basePoints = NULL;
	Point* offsetPoints = NULL;
	int baseSize = 0, baseCap = 10;
	int offsetSize = 0, offsetCap = 10;

	reset_points(&basePoints, &baseSize, &baseCap);
	reset_points(&offsetPoints, &offsetSize, &offsetCap);

	int inTSection = 0;
	int inOffsetMode = 0;

	while (fgets(line, sizeof(line), fp)) {
		line[strcspn(line, "\r\n")] = 0; // Remove newline

		if (strncmp(line, "T", 1) == 0 && strlen(line) <= 4) {
			// 輸出前一組加總結果（如果有）
			if (baseSize > 0 && offsetSize > 0) {
				int count = (baseSize < offsetSize) ? baseSize : offsetSize;
				for (int i = 0; i < count; i++) {
					Point sum = {
						basePoints[i].x + offsetPoints[i].x,
						basePoints[i].y + offsetPoints[i].y
					};
					print_point(fout, sum);
				}
			}

			// 新區塊開始
			inTSection = 1;
			inOffsetMode = 0;
			reset_points(&basePoints, &baseSize, &baseCap);
			reset_points(&offsetPoints, &offsetSize, &offsetCap);
			fprintf(fout, "%s\n", line);
			continue;
		}

		if (!inTSection) {
			fprintf(fout, "%s\n", line);
			continue;
		}

		if (strncmp(line, "M02", 3) == 0 || strncmp(line, "M08", 3) == 0) {
			// 輸出當前組加總
			if (baseSize > 0 && offsetSize > 0) {
				int count = (baseSize < offsetSize) ? baseSize : offsetSize;
				for (int i = 0; i < count; i++) {
					Point sum = {
						basePoints[i].x + offsetPoints[i].x,
						basePoints[i].y + offsetPoints[i].y
					};
					print_point(fout, sum);
				}
			}

			fprintf(fout, "%s\n", line);
			inTSection = 0;
			continue;
		}

		if (strncmp(line, "M01", 3) == 0) {
			inOffsetMode = 1;
			continue;
		}

		int x = 0, y = 0;
		if (parse_coordinate(line, &x, &y)) {
			Point p = { x, y };
			if (!inOffsetMode) {
				basePoints = add_point(basePoints, &baseSize, &baseCap, p);
				print_point(fout, p); // 輸出原始點
			}
			else {
				offsetPoints = add_point(offsetPoints, &offsetSize, &offsetCap, p);
			}
		}
		else {
			// 其他文字照常輸出
			fprintf(fout, "%s\n", line);
		}
	}

	// 最後一組檢查
	if (inTSection && baseSize > 0 && offsetSize > 0) {
		int count = (baseSize < offsetSize) ? baseSize : offsetSize;
		for (int i = 0; i < count; i++) {
			Point sum = {
				basePoints[i].x + offsetPoints[i].x,
				basePoints[i].y + offsetPoints[i].y
			};
			print_point(fout, sum);
		}
	}

	// 清理
	free(basePoints);
	free(offsetPoints);
	fclose(fp);
	fclose(fout);
	return 0;
}
#endif
