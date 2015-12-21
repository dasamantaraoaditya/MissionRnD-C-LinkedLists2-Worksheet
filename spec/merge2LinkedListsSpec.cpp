#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/merge2LinkedLists.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(merge2LinkedListsSpec)
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
			Assert::IsNull(merge2LinkedLists(NULL, NULL), L"Null check failed.", LINE_INFO());
		}

		TEST_METHOD(oneLinkedListNullCheck)
		{
			Assert::IsTrue(compare(merge2LinkedLists(NULL, createList(123)), 123), L"First linked list Null check failed.", LINE_INFO());
			Assert::IsTrue(compare(merge2LinkedLists(createList(123), NULL), 123), L"Second linked list Null check failed.", LINE_INFO());
		}

		TEST_METHOD(sameLinkedLists)
		{
			Assert::IsTrue(compare(merge2LinkedLists(createList(123), createList(123)), 112233), L"Merge same linked lists case failed.", LINE_INFO());
		}

		TEST_METHOD(sortedLinkedListsUnEqualLength)
		{
			Assert::IsTrue(compare(merge2LinkedLists(createList(123), createList(45)), 12345), L"Merge linked lists unequal length case failed.", LINE_INFO());
			Assert::IsTrue(compare(merge2LinkedLists(createList(79), createList(1)), 179), L"Merge linked lists unequal length case failed.", LINE_INFO());
			Assert::IsTrue(compare(merge2LinkedLists(createList(14), createList(4678)), 144678), L"Merge linked lists unequal length case failed.", LINE_INFO());
		}

		TEST_METHOD(sortedLinkedListsEqualLength)
		{
			Assert::IsTrue(compare(merge2LinkedLists(createList(123), createList(456)), 123456), L"Merge linked lists equal length case failed.", LINE_INFO());
			Assert::IsTrue(compare(merge2LinkedLists(createList(789), createList(123)), 123789), L"Merge linked lists equal length case failed.", LINE_INFO());
			Assert::IsTrue(compare(merge2LinkedLists(createList(246), createList(135)), 123456), L"Merge linked lists equal length case failed.", LINE_INFO());
			Assert::IsTrue(compare(merge2LinkedLists(createList(125), createList(237)), 122357), L"Merge linked lists equal length case failed.", LINE_INFO());
			Assert::IsTrue(compare(merge2LinkedLists(createList(146), createList(468)), 144668), L"Merge linked lists equal length case failed.", LINE_INFO());
		}
	};
}