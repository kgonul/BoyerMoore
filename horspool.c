#include <stdio.h>
#include<string.h>
#include<time.h>
#include<sys/resource.h>
#define MAX 500
int t[MAX];
void shifttable(char p[])
{
    int i,j,m;
    m=(int)strlen(p);
    for(i=0;i<MAX;i++)
        t[i]=m;
    for(j=0;j<m-1;j++)
        t[p[j]]=m-1-j;
    
    printf("\n");
    for(int i=0;i<m;i++) {
        printf("%c: %d ", p[i], t[p[i]]);
    }
    printf("\n");
}
int horspool(char src[],char p[])
{
    
    int i,k,m,n;
    n=(int)strlen(src);
    m=(int)strlen(p);
    printf("nLength of text=%d",n);
    printf("n Length of pattern=%d",m);
    i=m-1;
    while(i<n)
    {
        k=0;
        while((k<m)&&(p[m-1-k]==src[i-k]))
            k++;
        if(k==m)
            return(i-m+1);
        else {
            i+=t[src[i]];
            printf("shift: %d\n", t[src[i]]);
        }
    }
    return -1;
}
int main()
{
    char src[100],p[100];
    clock_t start,end=0;
    double CPU_time_used;
    struct rusage r_usage;
    getrusage(RUSAGE_SELF,&r_usage);
    int pos;
    
    printf("Enter the text in which pattern is to be searched\n");
    scanf("%24s", src);
    printf("Enter the pattern to be searched\n");
    scanf("%24s", p);
    shifttable(p);
    start=clock();
    pos=horspool(src,p);
    end=clock();
    if(pos>=0)
        printf("\n The desired pattern was found starting from position %d",pos+1);
    else
        printf("\n The pattern was not found in the given textn");
    CPU_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("\n TIME %lf \n",CPU_time_used);
    printf("\n Memory used %ld Kb \n",r_usage.ru_maxrss);
    return 0;
}
