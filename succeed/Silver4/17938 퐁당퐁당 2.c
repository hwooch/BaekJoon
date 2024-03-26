#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 17938 _ 퐁당퐁당 2

// 문제
// 퐁당퐁당은 술게임 중 팀워크가 가장 중요한 MT 단골 게임이다.
// 매 차례마다 지정된 수의 팔을 동시에 들어야 하는데, 이를 실패하면 팔을 들어야했던 사람과 실수로 팔을 든 사람 모두 연좌제로 마셔야 하기 때문이다.
// 퐁당퐁당 게임의 규칙은 아래와 같다.
// 
// 1번 사람부터 N번 사람까지 순서대로 총 N명의 사람들이 원 모양을 이루어 반시계방향으로 둘러앉는다.
// 이 때 모든 사람들은 원의 중앙을 바라보고 앉는다.
// 게임은 1번 사람의 왼팔부터 시작하여 원의 바깥에서 보았을 때 왼쪽에서 오른쪽으로 진행한다.
// 첫 번째 차례 이후 매 차례마다 가장 오른쪽 사람이 들었던 팔의 다음 팔부터 진행하고, 순서대로 지정된 수만큼의 팔을 들어올린다.
// 게임을 시작할 때 들어야 하는 팔의 갯수는 1개이다.
// 시작하여 차례가 지날 때마다 들어야 하는팔의 개수는 1씩 증가한다.
// 들어야 하는 팔의 갯수가 2 × N 개가 되었다면 다음 차례부터 1씩 감소시킨다.
// 들어야 하는 팔의 갯수가 1개가 되었다면 다음 차례부터 다시 1씩 증가시킨다.
// 즉, 매 차례에 들어야 할 팔의 갯수는 1 이상 2 × N 이하로 유지된다.
// 엠티에서 퐁당퐁당 게임을 하던 휘수는 친구들이 너무 잘하는 것을 보고 재미가 없어져, 
// 최대한 많은 사람을 먹이기 위해 자기가 해당하는 차례에 일부러 팔을 들지 않으려고 한다.
// 휘수는 매 차례마다 자기가 트롤을 해서 사람들과 다 같이 술을 먹을 수 있을지 알고 싶어 한다.
// 여러분이 휘수를 도와주자!
// 
// 입력
// 첫 번째 줄에 게임에 참여하는 사람수 N이 정수로 주어진다. (2 ≤ N ≤ 1, 000)
// 
// 두 번째 줄에는 휘수의 위치 P와 차례 T가 정수로 주어진다. (1 ≤ P ≤ N, 1 ≤ T ≤ 10, 000, 000)
// 
// 출력
// 만약 T번째 차례에 휘수가 팔을 들어야 해서, 
// 휘수가 트롤을 성공할 수 있다면 “Dehet YeonJwaJe ^ ~^ ”을 출력하고, 
// 휘수가 트롤을 할 수 없는 위치라면 “Hing…NoJam”을 출력한다.

int user[2002] = { 0, };

int main() {
	int N;
	scanf("%d", &N); // 사람 수

	int size = N * 2; // 손 수

	int troll_user; // 게임에 걸려야 하는 사람
	int turn; // 몇턴째를 구하는건지

	int cycle = 0; // 사이클 크기
	for (int i = 1; i <= N * 2 - 1; i++) {
		cycle = cycle + i * 2;
	}
	cycle = cycle + N * 2 - 1;

	int temp = 0;
	int devide = (size - 1) * 2;
	scanf("%d %d", &troll_user, &turn);

	temp = turn / devide;
	cycle = cycle * temp;
	turn--;

	turn = turn % devide + 1;
	int start = 1;

	int count = 0;
	int sum = 0;
	int check = 0;
	int memorysum = 0;

	for (int i = 0; i < turn; i++) {
		if (check == 0) {
			count++;
			sum = sum + count;
			if (count == size) {
				check = 1;
			}
		}
		else if (check == 1) {
			count--;
			sum = sum + count;
			if (count == 1) {
				check = 0;
			}
		}
		memorysum = count;
	}
	for (int i = sum - memorysum + 1 + cycle; i <= sum + cycle; i++) {

		int qwer = (((i - 1) % size) + 1);
		int qwer2 = troll_user * 2;

		if (qwer == qwer2 - 1 || qwer == qwer2) {
			printf("Dehet YeonJwaJe ^~^");
			return 0;
		}

	}
	printf("Hing...NoJam");
}