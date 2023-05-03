#include <stdio.h>
#include <math.h>


int p[3]; // three pegs
int N; // number of disks
int M; // counter for number of moves
int K; // number of state to be displayed (-1 = all states)

// -------------------------------------------------------------------------
void print_disk(int d, char c) {
    int k;
    for (k = 0; k < N-d+1; k++) { 
        printf(" "); 
    }
    for (k = 0; k < 2*d-1; k++) { 
        printf("%c", c); 
    }
    for (k = 0; k < N-d+1; k++) { 
        printf(" "); 
    }
}

// -------------------------------------------------------------------------
void print_pegs() {
    int i, j, l;
    int t[3] = { p[0], p[1], p[2] };
    if (M != K && K != -1) { 
        return; 
    }
    printf("Tower of Hanoi pegs after %d moves:\n", M);
    j = pow(10, N-1);
    for (l = 0; l < N; l++) {
        for (i = 0; i < 3; i++) {
            if (t[i] / j != 0) {
                print_disk(t[i]%10, '*');
                t[i] = t[i] / 10;
            } else {
                print_disk(1, ' ');
            }
        }
        j = j / 10;
        printf("\n");
    }
}

// -------------------------------------------------------------------------
void Hanoi(int n, int A, int B, int C) {
    if (n == 0) {
        return;
    }
    Hanoi(n-1, A, C, B);
    p[B] = p[B] * 10 + p[A] % 10;
    p[A] = p[A] / 10;
    M++;
    print_pegs();
    Hanoi(n-1, C, B, A);
}

// -------------------------------------------------------------------------
int main(int argc, char **argv) {
    sscanf(argv[1], "%d", &N);
    sscanf(argv[2], "%d", &K);

    int m = 1;
    p[1] = 0;
    p[2] = 0;
    for (int i = 0; i < N; i++) {
        p[0] = p[0] + (i + 1) * m;
        m = m * 10;
    }

    M = 0;
    print_pegs();
    Hanoi(N, 0, 1, 2);
}
