# include <stdio.h>

int main()
{
    int stack[1001] = {0};
    int N, input;
    register int top, currentNumber, inputCount;
    while (scanf("%d", &N) && N)
        while (scanf("%d", &input) && input)
        {
            top = 0;
            currentNumber = 0;
            inputCount = 1;
            do {
                stack[++top] = ++currentNumber;
                while (stack[top] == input)
                {
                    top--;

                    if (inputCount != N)
                    {
                        scanf("%d", &input);
                        inputCount++;
                    }
                    else break;
                }
            } while (currentNumber != N);

            if (top)
            {
                printf("No\n");
                while (getchar() != '\n')
                    ;
            }
            else printf("Yes\n");
        }
}