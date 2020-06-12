from unittest import TestCase
import try_pybind11_olned as m


class MainTest(TestCase):
    def test_add(self):
        self.assertEqual(m.add(1, 2), 3)

    def test_subtract(self):
        self.assertEqual(m.subtract(3, 1), 2)


if __name__ == '__main__':
    unittest.main()
