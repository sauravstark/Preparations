#include<iostream>

int main()
 {
	int T;
	scanf("%d", &T);
	
	for (int i = 0; i < T; ++i) {
	    int N;
        scanf("%d", &N);
        int last;
        scanf("%d", &last);
        int curr;
        for (int i = 1; i < N; ++i) {
            scanf("%d", &curr);
            if (curr < last)
                printf("%d ", curr);
            else
                printf("-1 ");
            last = curr;
        }
        printf("-1\n");
	}
	
	return 0;
}