#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/reverseLinkedList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(reverseLinkedListSpec)
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
			Assert::IsNull(reverseLinkedList(NULL), L"Null check failed.", LINE_INFO());
		}

		TEST_METHOD(singleNode)
		{
			Assert::IsTrue(compare(reverseLinkedList(createList(2)), 2), L"Single node case failed.", LINE_INFO());
		}

		TEST_METHOD(twoNodes)
		{
			Assert::IsTrue(compare(reverseLinkedList(createList(25)), 52), L"Two nodes case failed.", LINE_INFO());
		}

		TEST_METHOD(multipleNodes)
		{
			Assert::IsTrue(compare(reverseLinkedList(createList(289)), 982), L"Multiple nodes case failed.", LINE_INFO());
			Assert::IsTrue(compare(reverseLinkedList(createList(908234)), 432809), L"Multiple nodes case failed.", LINE_INFO());
			Assert::IsTrue(compare(reverseLinkedList(createList(00000)), 00000), L"Multiple nodes case failed.", LINE_INFO());
			Assert::IsTrue(compare(reverseLinkedList(createList(347634437)), 734436743), L"Multiple nodes case failed.", LINE_INFO());
			Assert::IsTrue(compare(reverseLinkedList(createList(223344)), 443322), L"Multiple nodes case failed.", LINE_INFO());
		}
	};
}