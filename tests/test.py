from unittest import TestCase, main
import try_pybind11_olned as m


class ArithmeticTest(TestCase):
    def test_add(self):
        self.assertEqual(m.add(1, 2), 3)

    def test_subtract(self):
        self.assertEqual(m.subtract(3, 1), 2)


class PetTest(TestCase):

    def test_dog_go(self):
        d = m.Dog()
        self.assertEqual(d.go(2), "woof! woof!")

    def test_call_go_cat(self):
        class Cat(m.Animal):
            def go(self, n_times):
                return "meow! " * n_times

        c = Cat()
        self.assertEqual(m.call_go(c), "meow! meow! meow! ")

    def test_dachshund(self):
        class Dachshund(m.Dog):
            def __init__(self, name):
                m.Dog.__init__(self) # Without this, undefined behavior may occur if the C++ portions are referenced.
                self.name = name
            def bark(self):
                return "yap!"

        d = Dachshund("Iza")
        self.assertEqual(m.call_go(d), "woof! woof! woof!")


if __name__ == '__main__':
    main()
