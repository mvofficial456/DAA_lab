// q - Merge sort vs. modified merge sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int i=0;i<n2;i++) R[i]=a[m+1+i];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2) {
        if(L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }

    while(i<n1) a[k++] = L[i++];
    while(j<n2) a[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int a[], int l, int r) {
    if(l < r) {
        int m = (l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

void merge3(int a[], int l, int m1, int m2, int r) {
    int *temp = malloc((r-l+1) * sizeof(int));

    int i=l, j=m1+1, k=m2+1, t=0;

    while(i<=m1 || j<=m2 || k<=r) {
        int min = 1e9, src = -1;

        if(i<=m1 && a[i]<min) { min=a[i]; src=1; }
        if(j<=m2 && a[j]<min) { min=a[j]; src=2; }
        if(k<=r  && a[k]<min) { min=a[k]; src=3; }

        temp[t++] = min;

        if(src==1) i++;
        else if(src==2) j++;
        else k++;
    }

    for(i=0;i<t;i++)
        a[l+i] = temp[i];

    free(temp);
}

void mergeSort3(int a[], int l, int r) {
    if(l < r) {
        int third = (r-l)/3;

        int m1 = l + third;
        int m2 = l + 2*third;

        mergeSort3(a,l,m1);
        mergeSort3(a,m1+1,m2);
        mergeSort3(a,m2+1,r);

        merge3(a,l,m1,m2,r);
    }
}

int main() {
    FILE *fp = fopen("merge_growth.dat","w");

    for(int n=1000; n<=20000; n+=1000) {
        int *a = malloc(n*sizeof(int));
        int *b = malloc(n*sizeof(int));

        for(int i=0;i<n;i++) {
            a[i] = rand();
            b[i] = a[i];
        }

        clock_t s1 = clock();
        mergeSort(a,0,n-1);
        clock_t e1 = clock();

        clock_t s2 = clock();
        mergeSort3(b,0,n-1);
        clock_t e2 = clock();

        double t1 = (double)(e1-s1)/CLOCKS_PER_SEC;
        double t2 = (double)(e2-s2)/CLOCKS_PER_SEC;

        fprintf(fp,"%d %lf %lf\n",n,t1,t2);

        free(a);
        free(b);
    }

    fclose(fp);
    printf("Timing data written to merge_growth.dat\n");

    return 0;
}