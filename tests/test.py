from unittest import TestCase, main
import example as m


class ArithmeticTest(TestCase):
    def test_add(self):
        self.assertEqual(m.add(1, 2), 3)

    def test_subtract(self):
        self.assertEqual(m.subtract(3, 1), 2)


class Dachshund(m.Dog):
    def __init__(self, name):
        # Without this, undefined behavior may occur if the C++ portions are referenced.
        m.Dog.__init__(self)
        self._name = name

    def name(self):
        return self._name

    def bark(self):
        return "yap!"


class Cat(m.Animal):
    def go(self, n_times):
        return "meow! " * n_times


class CatTest(TestCase):
    def setUp(self):
        self.cat = Cat()

    def test_call_go(self):
        self.assertEqual(m.call_go(self.cat), "meow! meow! meow! ")

    def test_name(self):
        self.assertEqual(self.cat.name(), "unknown")

    def test_get_name(self):
        self.assertEqual(m.get_name(self.cat), "unknown")


class DogTest(TestCase):
    def setUp(self):
        self.dog = m.Dog()

    def test_call_go(self):
        self.assertEqual(self.dog.go(2), "woof! woof!")

    def test_name(self):
        self.assertEqual(self.dog.name(), "unknown")

    def test_get_name(self):
        self.assertEqual(m.get_name(self.dog), "unknown")


class DachshundTest(TestCase):
    def setUp(self):
        self.iza = Dachshund("Iza")

    def test_call_go(self):
        self.assertEqual(m.call_go(self.iza), "yap! yap! yap!")

    def test_name(self):
        self.assertEqual(self.iza.name(), "Iza")

    def test_get_name(self):
        self.assertEqual(m.get_name(self.iza), "Iza")


class HuskyTest(TestCase):
    def setUp(self):
        self.dog = m.Husky()

    def test_call_go(self):
        self.assertEqual(self.dog.go(2), "woof! woof!")

    def test_name(self):
        self.assertEqual(self.dog.name(), "unknown")

    def test_get_name(self):
        self.assertEqual(m.get_name(self.dog), "unknown")


class ParserTest(TestCase):
    def setUp(self):
        self.parser = m.Parser()
        self.value = 0
        self.parser.set_callback(self.set_value)
        self.parser.set_strcallback(self.set_structure)

    def set_value(self, n: int):
        self.value = n

    def set_structure(self, n: int):
        self.value = n

    def test_callback(self):
        v = "10"
        self.parser.parse(v)
        self.assertEqual(self.value, int(v))

    
    def test_strcallback(self):
        v = "i10"
        self.parser.parse(v)
        print(self.value, self.value.value)
        self.assertEqual(self.value.value, int(v[1:]))


if __name__ == '__main__':
    main()
