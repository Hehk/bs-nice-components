open Jest;

describe("Expect", () => {
  open Expect;
  open! Expect.Operators;

  test("==", () => expect(1 + 2) === 3)
});
