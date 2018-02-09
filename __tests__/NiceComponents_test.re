open Jest;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

describe("make", () => {
  open Expect;
  module Basic = (val NiceComponents.make(~tag="div", ~debugName="Basic", [||]));
  test("Basic component renders", () =>
    Enzyme.shallow(<Basic />) |> Enzyme.exists |> expect |> toBe(true)
  );
});
