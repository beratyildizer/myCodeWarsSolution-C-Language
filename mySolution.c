#include "mySolution.h" 

void fun(char* p) {
    size_t size = strlen(p);
    for (size_t i = 0; i < (size / 2); ++i) {
        char temp = p[i];
        p[i] = p[size - 1 - i];
        p[size - 1 - i] = temp;
    }
}

char* strsum(const char* a, const char* b)
{
    while (*a == '0' && strlen(a) > 1)
        ++a;
    while (*b == '0' && strlen(b) > 1)
        ++b;
    size_t size1 = strlen(a);
    size_t size2 = strlen(b);
    char* aa = (char*)calloc(size1 + 1, sizeof(char));
    char* bb = (char*)calloc(size2 + 1, sizeof(char));
    strcpy(aa, a);
    strcpy(bb, b);
    char* sum = (char*)calloc(500, sizeof(char));
    fun(aa);
    fun(bb);
    int k = 0;
    int sum1 = 0;
    size_t i = 0;
    for (i = 0; i < 500; ++i) {
        if (i >= size1 && i >= size2)
            break;
        sum1 = 0;
        if (i < size1)
            sum1 = (aa[i] - 48);
        if (i < size2)
            sum1 += (bb[i] - 48);
        sum1 += k;
        if (sum1 > 9) {
            k = sum1 / 10;
            sum1 %= 10;
        }
        else
            k = 0;
        sum[i] = sum1 + '0';

    }
    if (k) {
        sum[i++] = k + '0';
    }
    sum[i] = '\0';
    free(aa);
    free(bb);
    fun(sum);
    return sum;

}

int loop_size(Node* node) {
    Node* slow = node;
    Node* fast = node;
    int c = 0;
    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    do {
        c++;
        fast = fast->next;
    } while (slow != fast);

    return c;
}



long parse_int(const char* number) {
    static const char* look_up_table[] = { "zero","one","two","three","four","five","six","seven","eight","nine","ten",
    "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen",
    "twenty","twenty-one","twenty-two","twenty-three","twenty-four","twenty-five","twenty-six","twenty-seven",
    "twenty-eight","twenty-nine",
    "thirty","thirty-one","thirty-two","thirty-three","thirty-four","thirty-five","thirty-six","thirty-seven",
    "thirty-eight","thirty-nine",
    "forty","forty-one","forty-two","forty-three","forty-four","forty-five","forty-six","forty-seven",
    "forty-eight","forty-nine",
    "fifty","fifty-one","fifty-two","fifty-three","fifty-four","fifty-five","fifty-six","fifty-seven","fifty-eight",
    "fifty-nine",
    "sixty","sixty-one","sixty-two","sixty-three","sixty-four","sixty-five","sixty-six","sixty-seven",
    "sixty-eight","sixty-nine",
    "seventy","seventy-one","seventy-two","seventy-three","seventy-four","seventy-five","seventy-six",
    "seventy-seven","seventy-eight","seventy-nine",
    "eighty","eighty-one","eighty-two","eighty-three","eighty-four","eighty-five","eighty-six",
    "eighty-seven","eighty-eight","eighty-nine",
    "ninety","ninety-one","ninety-two","ninety-three","ninety-four","ninety-five","ninety-six",
    "ninety-seven","ninety-eight","ninety-nine",
    };
    size_t size = strlen(number);
    char* new_number = (char*)malloc(size + 1);
    if (!new_number)
        return 0;
    (void)strcpy(new_number, number);
    long result = 0;
    unsigned int before = 0;
    const char* ptr = NULL;
    ptr = strtok(new_number, " ");
    int flag = 0;

    do {
        if (!strcmp(ptr, "hundred")) {
            result += (before * 100);
            flag = 1;
            before = 0;
            continue;
        }
        if (!strcmp(ptr, "thousand")) {
            if (flag) {
                before += result;
                result = 0;
                flag = 0;
            }
            result += (before * 1000);
            before = 0;
            continue;
        }
        if (!strcmp(ptr, "million")) {
            result += (before * 1000000);
            before = 0;
            continue;
        }
        if (!strcmp(ptr, "and")) {
            before = 0;
            continue;
        }
        for (size_t i = 0; i < 100; ++i) {
            if (!strcmp(ptr, look_up_table[i])) {
                before = (unsigned int)i;
                break;
            }
        }
    } while ((ptr = strtok(NULL, " ")));

    return result + before;
}

void spiralize(unsigned n, int spiral[N][N])
{
    int* p = (int*)spiral;
    int sayac = n - 1;
    int flag = 1;
    int direction = 0;
    int sum = 0;
    memset((void*)p, 0, sizeof(int) * n * n);
    for (int i = 0; i <= sayac; ++i)
    {
        *p = 1;
        if (sayac != i)
            ++p;
    }
    while (sayac > 0) {
        if (!flag && !direction) {
            if (sayac == 1)
                sayac = 0;
            for (int i = 0; i < sayac; ++i)
                *++p = 1;
            flag = 1;
            ++sum;
        }
        else if (!flag && direction) {
            if (sayac == 1)
                sayac = 0;
            for (int i = 0; i < sayac; ++i)
                *--p = 1;
            flag = 1;
            ++sum;
        }
        else if (flag && !direction) {
            for (int i = 0; i < sayac; ++i) {
                p += n;
                *p = 1;
            }
            flag = 0;
            ++sum;
            direction = 1;
        }
        else {
            for (int i = 0; i < sayac; ++i) {
                p -= n;
                *p = 1;
            }
            flag = 0;
            direction = 0;
            ++sum;
        }
        if (sum == 2) {
            sayac -= 2;
            sum = 0;
        }
    }
}

char* range_extraction(const int* args, size_t n)
{
    char* p = (char*)calloc(500, sizeof(char));
    int i = 0;
    int first = args[i];
    int second = args[i + 1];
    int flag = 0;
    int a = 0;
    while (n) {
        int first = args[i];
        int second = args[i + 1];
        if (abs(second - first) == 1) {
            flag++;
            ++i;
            --n;
            continue;
        }
        if (flag > 1) {
            sprintf(&p[strlen(p)], "%d-%d,", args[a], args[i]);
            flag = 0;
            a = 0;
            a += (i + 1);
        }
        else {
            if (flag == 1) {
                --i;
                ++n;
            }
            flag = 0;
            sprintf(&p[strlen(p)], "%d,", args[i]);
            a = 0;
            a += (i + 1);
        }
        ++i;
        --n;
    }
    p[strlen(p) - 1] = '\0';
    return p;
}