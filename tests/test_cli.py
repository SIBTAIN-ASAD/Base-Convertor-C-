"""Compile the menu program and exercise complete input/output sessions."""
import os
from pathlib import Path
import subprocess
import tempfile
import unittest


class MenuTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.output = tempfile.TemporaryDirectory()
        cls.addClassCleanup(cls.output.cleanup)
        cls.program = str(Path(cls.output.name) / "converter")
        source = Path(__file__).resolve().parents[1] / "code.cpp"
        subprocess.run([
            os.environ.get("CXX", "c++"), "-std=c++17", "-Wall", "-Wextra", "-Werror",
            str(source), "-o", cls.program,
        ], check=True)

    def run_menu(self, text):
        return subprocess.run(
            [self.program], input=text, text=True, capture_output=True, timeout=3, check=True,
        ).stdout

    def test_hex_output(self):
        self.assertIn("HEXADECIMAL: FF", self.run_menu("10\n16\n255\n0\nY\n"))

    def test_hex_to_octal(self):
        self.assertIn("OCTAL: 377", self.run_menu("16\n8\nff\n0\nY\n"))

    def test_zero(self):
        self.assertIn("BINARY: 0", self.run_menu("10\n2\n0\n0\nY\n"))

    def test_overflow_is_reported(self):
        self.assertIn("exceeds the supported integer range", self.run_menu(
            "10\n2\n999999999999999999999999999\n0\nY\n"
        ))

    def test_eof_and_nonnumeric_menu_exit(self):
        for text in ("", "invalid\n", "10\n", "10\n2\n", "10\n2\n-1\n"):
            with self.subTest(text=text):
                self.run_menu(text)


if __name__ == "__main__":
    unittest.main()
