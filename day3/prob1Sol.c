#include<stdio.h>
void countVotes(int votes[], int n, int candidateVotes[]) {
                                        //{4 3 1 1 1}
    for(int I = 0; I < n; I++) {
        candidateVotes[votes[I] - 1]++;
    }
}

int findWinner(int candidateVotes[]) {
    int max_index = 0;
    for(int I = 1; I < 5; I++) {
        if(candidateVotes[I] > candidateVotes[max_index]) {
            max_index = I;
        }
    }
    return max_index + 1;
}

void readVotes(int votes[], int n) {
    printf("Enter votes(1-Ashwin, 2-Anil, 3-Kavya, 4-Shakila, 5-Punya):");
    for(int I = 0; I < n; I++) {
        scanf("%d", &votes[I]);
    }
}

int main() {
    int n;// = 10;
    printf("Enter number of votes:");
    scanf("%d", &n);

    int votes[1000];//{1, 2, 2, 3, 1, 4, 2, 5, 1, 1};
    readVotes(votes, n);
    int candidateVotes[5] = {0, 0, 0, 0, 0};
    countVotes(votes, n, candidateVotes);
    for(int I = 0; I < 5; I++) {
        printf("Candiate %d votes are %d\n", I+1, candidateVotes[I]);
    }
    printf("Winner is %d", findWinner(candidateVotes));
    return 0;
}