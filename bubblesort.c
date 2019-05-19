
#include <stdio.h>

int main() {
        printf("Bubble sort\n");
        int *a;
        int i,j;
        int temp,n;
        printf("Enter size: ");
        scanf("%d",&n);
        a=(int *)malloc(n*sizeof(int));
        
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(i=n-1;i>=0;i--) {
                for(j=0;j<=i-1;j++) {
                    if(a[j]>a[j+1]) {
                        temp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                    }
                }
        }
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        return 0;
}

