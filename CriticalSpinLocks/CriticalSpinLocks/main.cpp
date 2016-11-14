#include <iostream>
#include "Test.h"

int main() {
	Test t("test");
	t.startProcess();
	std::cout << "main done" << std::endl;

	system("PAUSE");
}