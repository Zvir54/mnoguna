#include "pch.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

#include <gtest/gtest.h>
#include "pch.h" // ϳ�������� ��� ���� � ������ Set

// ���� ��� ��������� �������� �� �������
TEST(SetTest, AddElement) {
	Set<int> s;
	s.add(5);
	EXPECT_TRUE(s.Check(5)); // ��������, �� ���� ������� �������
	EXPECT_FALSE(s.Check(10)); // ��������, �� ������� 10 �� �������� � ������
}

// ���� ��� ��������� �������� � �������
TEST(SetTest, RemoveElement) {
	Set<int> s;
	s.add(5);
	s.remove(5);
	EXPECT_FALSE(s.Check(5)); // ��������, �� ������� ��� ������ ���������
}

// ���� ��� ��'������� ������
TEST(SetTest, Union) {
	Set<int> s1;
	s1.add(1);
	s1.add(2);
	Set<int> s2;
	s2.add(2);
	s2.add(3);

	Set<int> result = s1.union_(s2);

	EXPECT_TRUE(result.Check(1)); // ��������, �� �������� ������� 1
	EXPECT_TRUE(result.Check(2)); // ��������, �� �������� ������� 2
	EXPECT_TRUE(result.Check(3)); // ��������, �� �������� ������� 3
}

// ���� ��� �������� ������
TEST(SetTest, Intersect) {
	Set<int> s1;
	s1.add(1);
	s1.add(2);
	Set<int> s2;
	s2.add(2);
	s2.add(3);

	Set<int> result = s1.intersect(s2);

	EXPECT_FALSE(result.Check(1)); // ��������, �� ������� 1 �������
	EXPECT_TRUE(result.Check(2)); // ��������, �� �������� ������� 2
	EXPECT_FALSE(result.Check(3)); // ��������, �� ������� 3 �������
}

// ���� ��� ������ ������
TEST(SetTest, Difference) {
	Set<int> s1;
	s1.add(1);
	s1.add(2);
	Set<int> s2;
	s2.add(2);
	s2.add(3);

	Set<int> result = s1.difference(s2);

	EXPECT_TRUE(result.Check(1)); // ��������, �� �������� ������� 1
	EXPECT_FALSE(result.Check(2)); // ��������, �� ������� 2 �������
	EXPECT_FALSE(result.Check(3)); // ��������, �� ������� 3 �������
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
