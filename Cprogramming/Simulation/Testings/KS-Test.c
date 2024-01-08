#include <stdio.h>
float alpha;

struct KS {
    float numbers[20];
    float D, tabulatedD;
    float Dplusmax, Dminusmax;
    float Dplus[20], Dminus[20];
    float ratio[20], ratiominus[20];
    int i, j, n;
};

void getdata(struct KS *ks) {
    printf("How many numbers?:");
    scanf("%d", &ks->n);
    for (ks->i = 0; ks->i < ks->n; ks->i++) {
        printf("Enter %d number:", ks->i + 1);
        scanf("%f", &ks->numbers[ks->i]);
    }
}

void BubbleSort(struct KS *ks) {
    int i, j;
    float temp;
    for (i = 0; i < ks->n - 1; i++) {
        for (j = 0; j < ks->n - i - 1; j++) {
            if (ks->numbers[j] > ks->numbers[j + 1]) {
                temp = ks->numbers[j];
                ks->numbers[j] = ks->numbers[j + 1];
                ks->numbers[j + 1] = temp;
            }
        }
    }
    printf("\nThe numbers in ascending order is:\n");
    for (i = 0; i < ks->n; i++) {
        printf("%.2f ", ks->numbers[i]);
    }
}

void calculate(struct KS *ks) {
    for (ks->i = 0; ks->i < ks->n; ks->i++) {
        int j;
        j = ks->i + 1;
        ks->ratio[ks->i] = (float)j / ks->n;
        ks->ratiominus[ks->i] = (float)ks->i / ks->n;
        ks->Dplus[ks->i] = ks->ratio[ks->i] - ks->numbers[ks->i];
        ks->Dminus[ks->i] = ks->numbers[ks->i] - ks->ratiominus[ks->i];
    }
}

void display(struct KS *ks) {
    ks->Dplusmax = ks->Dplus[0];
    ks->Dminusmax = ks->Dminus[0];
    for (ks->i = 1; ks->i < ks->n; ks->i++) {
        if (ks->Dplus[ks->i] > ks->Dplusmax) {
            ks->Dplusmax = ks->Dplus[ks->i];
        }
        if (ks->Dminus[ks->i] > ks->Dminusmax) {
            ks->Dminusmax = ks->Dminus[ks->i];
        }
    }
    printf("\nD+ max: %.2f", ks->Dplusmax);
    printf("\nD- max: %.2f", ks->Dminusmax);
    printf("\nD = max(%.2f, %.2f) =", ks->Dplusmax, ks->Dminusmax);
    if (ks->Dplusmax > ks->Dminusmax) {
        ks->D = ks->Dplusmax;
    } else {
        ks->D = ks->Dminusmax;
    }
    printf(" %.2f\n", ks->D);
}

void conclusion(struct KS *ks) {
    printf("Enter the value of alpha:");
    scanf("%f", &alpha);
    printf("Enter the tabulated value:");
    scanf("%f", &ks->tabulatedD);

    if (ks->D <= ks->tabulatedD) {
        printf("For alpha = %f, The hypothesis is accepted.", alpha);
		printf("\nHence, given data are uniform.");
    } else {
        printf("For alpha = %f, The test is rejected.\n", alpha);
		printf("\nHence, given data are not uniform.");
    }
}

int main() {
    struct KS ks1;
	// Use: 0.44, 0.81, 0.14, 0.05, 0.93
    getdata(&ks1);
    BubbleSort(&ks1);
	// Use alpha = 0.05
    calculate(&ks1);
    display(&ks1);
    conclusion(&ks1);
	printf("\nName: Giver Khadka\tRoll no.: 05");
    return 0;
}
