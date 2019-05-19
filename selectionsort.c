#include <stdio.h>

int main() {
        printf("Selection sort\n");
        int *a;
        int i,j;
        int min,temp,n;
        printf("Enter size: ");
        scanf("%d",&n);
        a=(int *)malloc(n*sizeof(int));
        
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(i=0;i<n-1;i++) {
                min=i;
                for(j=i+1;j<n;j++) {
                        if(a[j]<a[min]) {
                            min=j;
                        }
                }
                temp=a[min];
                a[min]=a[i];
                a[i]=temp;
        }
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        return 0;
}

