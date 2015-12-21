#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/insertAtEveryKthNode.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(insertAtEveryKthNodeSpec)
	{
	public:

		struct node * createNode(int num) {
			struct node *newNode = (struct node *)malloc(sizeof(struct node));
			newNode->num = num;
			newNode->next = NULL;
			return newNode;
		}

		struct node * createList(int num) {
			struct node *head = createNode(num % 10);
			num /= 10;
			while (num) {
				struct node *newNode = createNode(num % 10);
				newNode->next = head;
				head = newNode;
				num /= 10;
			}
			return head;
		}

		bool compare(struct node *result, int num) {
			struct node *head = createList(num);
			while (head && result && head->num == result->num) {
				head = head->next;
				result = result->next;
			}
			return !head && !result;
		}

		TEST_METHOD(nullCheck)
		{
			Assert::IsNull(insertAtEveryKthNode(NULL, 2), L"Null check failed.", LINE_INFO());
		}

		TEST_METHOD(InvalidKValue)
		{
			Assert::IsNull(insertAtEveryKthNode(NULL, 0), L"K Value zero test failed.", LINE_INFO());
			Assert::IsNull(insertAtEveryKthNode(NULL, -2), L"K Value -2 test failed.", LINE_INFO());
		}

		TEST_METHOD(KValueGreaterThanLength)
		{
			Assert::IsTrue(compare(insertAtEveryKthNode(createList(28349), 9), 28349), L"K value greater than length case failed.", LINE_INFO());
		}

		TEST_METHOD(validKValue)
		{
			Assert::IsTrue(compare(insertAtEveryKthNode(createList(289), 1), 218191), L"K value one case failed.", LINE_INFO());
			Assert::IsTrue(compare(insertAtEveryKthNode(createList(222), 2), 2222), L"K value two case failed.", LINE_INFO());
			Assert::IsTrue(compare(insertAtEveryKthNode(createList(56934), 3), 569334), L"K value one case failed.", LINE_INFO());
			Assert::IsTrue(compare(insertAtEveryKthNode(createList(12345), 2), 1223425), L"K value one case failed.", LINE_INFO());
		}

	};
}