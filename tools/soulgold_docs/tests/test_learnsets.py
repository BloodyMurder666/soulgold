from __future__ import annotations

import unittest

from tools.soulgold_docs.parsers.learnsets import parse_dedicated_tutors


class DedicatedTutorTests(unittest.TestCase):
    def test_draco_meteor_has_exclusive_tutor_note(self) -> None:
        self.assertEqual(
            parse_dedicated_tutors()["MOVE_DRACO_METEOR"],
            "Exclusive to the Dragon's Den Shrine tutor",
        )


if __name__ == "__main__":
    unittest.main()
