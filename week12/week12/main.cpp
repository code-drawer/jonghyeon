#include "bread.h"

int main() {
	bread 김연경("중력분", "백각 계란", "이즈니 버터");
	김연경.재료();

	김연경.set_밀가루("강력분");
	김연경.재료();

	cout << 김연경.get_밀가루() << endl;

	return 0;
}
