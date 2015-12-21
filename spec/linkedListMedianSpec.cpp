#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/linkedListMedian.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(linkedListMedianSpec)
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

		TEST_METHOD(nullCheck)
		{
			Assert::AreEqual(linkedListMedian(NULL), -1, L"Null check failed.", LINE_INFO());
		}

		TEST_METHOD(oddLength)
		{
			Assert::AreEqual(linkedListMedian(createList(3)), 3, L"Odd length check failed.", LINE_INFO());
			Assert::AreEqual(linkedListMedian(createList(345)), 4, L"Odd length check failed.", LINE_INFO());
			Assert::AreEqual(linkedListMedian(createList(23789)), 7, L"Odd length check failed.", LINE_INFO());
			Assert::AreEqual(linkedListMedian(createList(44444)), 4, L"Odd length check failed.", LINE_INFO());
		}

		TEST_METHOD(evenLength)
		{
			Assert::AreEqual(linkedListMedian(createList(19)), 5, L"Even length check failed.", LINE_INFO());
			Assert::AreEqual(linkedListMedian(createList(3456)), 4, L"Even length check failed.", LINE_INFO());
			Assert::AreEqual(linkedListMedian(createList(123678)), 4, L"Even length check failed.", LINE_INFO());
			Assert::AreEqual(linkedListMedian(createList(555555)), 5, L"Even length check failed.", LINE_INFO());
		}
	};
}