#include "pch.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

#include <gtest/gtest.h>
#include "pch.h" // Підключіть ваш файл з класом Set

// Тест для додавання елементів до множини
TEST(SetTest, AddElement) {
	Set<int> s;
	s.add(5);
	EXPECT_TRUE(s.Check(5)); // Перевірка, чи вірно доданий елемент
	EXPECT_FALSE(s.Check(10)); // Перевірка, що елемент 10 не міститься в множині
}

// Тест для видалення елементів з множини
TEST(SetTest, RemoveElement) {
	Set<int> s;
	s.add(5);
	s.remove(5);
	EXPECT_FALSE(s.Check(5)); // Перевірка, що елемент був успішно видалений
}

// Тест для об'єднання множин
TEST(SetTest, Union) {
	Set<int> s1;
	s1.add(1);
	s1.add(2);
	Set<int> s2;
	s2.add(2);
	s2.add(3);

	Set<int> result = s1.union_(s2);

	EXPECT_TRUE(result.Check(1)); // Перевірка, чи присутній елемент 1
	EXPECT_TRUE(result.Check(2)); // Перевірка, чи присутній елемент 2
	EXPECT_TRUE(result.Check(3)); // Перевірка, чи присутній елемент 3
}

// Тест для перетину множин
TEST(SetTest, Intersect) {
	Set<int> s1;
	s1.add(1);
	s1.add(2);
	Set<int> s2;
	s2.add(2);
	s2.add(3);

	Set<int> result = s1.intersect(s2);

	EXPECT_FALSE(result.Check(1)); // Перевірка, що елемент 1 відсутній
	EXPECT_TRUE(result.Check(2)); // Перевірка, чи присутній елемент 2
	EXPECT_FALSE(result.Check(3)); // Перевірка, що елемент 3 відсутній
}

// Тест для різниці множин
TEST(SetTest, Difference) {
	Set<int> s1;
	s1.add(1);
	s1.add(2);
	Set<int> s2;
	s2.add(2);
	s2.add(3);

	Set<int> result = s1.difference(s2);

	EXPECT_TRUE(result.Check(1)); // Перевірка, чи присутній елемент 1
	EXPECT_FALSE(result.Check(2)); // Перевірка, що елемент 2 відсутній
	EXPECT_FALSE(result.Check(3)); // Перевірка, що елемент 3 відсутній
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
