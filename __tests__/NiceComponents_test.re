open Jest;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

describe("make", () => {
  open Expect;
  test("Basic component renders", () => {
    module Basic = (val NiceComponents.make(~tag="div", [||]));
    Enzyme.shallow(<Basic />) |> Enzyme.exists |> expect |> toBe(true);
  });
  test("Component tag changes if ~tag is different", () => {
    let tag = "footer";
    module Test = (val NiceComponents.make(~tag, [||]));
    Enzyme.shallow(<Test />) |> Enzyme.type_ |> expect |> toBe(tag);
  });
  test("Component debugName defaults to it's tag", () => {
    let tag = "table";
    module Test = (val NiceComponents.make(~tag, [||]));
    Enzyme.shallow(<Test />) |> Enzyme.name |> expect |> toBe(tag);
  });
});

/* A small subset of the tags */
describe("NiceComponents.<tag> renders the correct tag", () => {
  open Expect;
  let noStyle = [||];
  test("NiceComponents.div renders a div", () => {
    module Div = (val NiceComponents.div(noStyle));
    Enzyme.shallow(<Div />) |> Enzyme.type_ |> expect |> toBe("div");
  });
  test("NiceComponents.h1 renders a h1", () => {
    module H1 = (val NiceComponents.h1(noStyle));
    Enzyme.shallow(<H1 />) |> Enzyme.type_ |> expect |> toBe("h1");
  });
  test("NiceComponents.span renders a span", () => {
    module Span = (val NiceComponents.span(noStyle));
    Enzyme.shallow(<Span />) |> Enzyme.type_ |> expect |> toBe("span");
  });
  test("NiceComponents.button renders a button", () => {
    module Button = (val NiceComponents.button(noStyle));
    Enzyme.shallow(<Button />) |> Enzyme.type_ |> expect |> toBe("button");
  });
  test("NiceComponents.header renders a header", () => {
    module Header = (val NiceComponents.header(noStyle));
    Enzyme.shallow(<Header />) |> Enzyme.type_ |> expect |> toBe("header");
  });
});
