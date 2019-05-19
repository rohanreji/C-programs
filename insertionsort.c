#include <stdio.h>
#include <malloc.h>
int main() {
        printf("Insetion sort\n");
        int *a;
        int i,j;
        int temp,n,key;
        printf("Enter size: ");
        scanf("%d",&n);
        a=(int *)malloc(n*sizeof(int));
        
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(i=1;i<n;i++) {
            key=a[i];
            for(j=i;j>0;j--){
                if(a[j] < a[j-1]) {
                    a[j]=a[j-1];
                }
                else {
                    break;
                }
            }
            a[j]=key;
        }
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        return 0;
}

