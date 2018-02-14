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

describe("addStyles function", () => {
  open Expect;
  open Nice;
  test("Adds styles to unstyled component", () => {
    let styles = [|Nice.Color(Red)|];
    module UnStyled = (val NiceComponents.make(~tag="div", [||]));
    module Styled = (val NiceComponents.addStyles(styles, (module UnStyled)));
    styles |> expect |> toEqual(Styled.__styles);
  });
  test("new styles are appended to old ones", () => {
    let styles = [|Color(Red)|];
    let newStyles = [|Color(White)|];
    module Original = (val NiceComponents.make(~tag="div", styles));
    module Modified = (val NiceComponents.addStyles(newStyles, (module Original)));
    Array.append(newStyles, styles) |> expect |> toEqual(Modified.__styles);
  });
  test("ClassNames should not equal before and after adding styles", () => {
    let styles = [|Color(Red)|];
    let newStyles = [|BackgroundColor(White)|];
    module Original = (val NiceComponents.make(~tag="div", styles));
    module Modified = (val NiceComponents.addStyles(newStyles, (module Original)));
    Original.className === Modified.className |> expect |> toBe(false);
  });
});

describe("AddStyles functor", () => {
  open Expect;
  open Nice;
  test("Adds styles to unstyled component", () => {
    let styles = [|Nice.Color(Red)|];
    module UnStyled = (val NiceComponents.make(~tag="div", [||]));
    module Styled =
      NiceComponents.AddStyles(
        {
          let newStyles = styles;
        },
        UnStyled
      );
    styles |> expect |> toEqual(Styled.__styles);
  });
  test("new styles are appended to old ones", () => {
    let styles = [|Nice.Color(Red)|];
    let newStyles = [|BackgroundColor(White)|];
    module Original = (val NiceComponents.make(~tag="div", styles));
    module Modified = NiceComponents.AddStyles({ let newStyles = newStyles }, Original);
    Array.append(newStyles, styles) |> expect |> toEqual(Modified.__styles);
  });
  test("ClassNames should not equal before and after adding styles", () => {
    let styles = [|Color(Red)|];
    let newStyles = [|BackgroundColor(White)|];
    module Original = (val NiceComponents.make(~tag="div", styles));
    module Modified = NiceComponents.AddStyles({ let newStyles = newStyles }, Original);
    Original.className === Modified.className |> expect |> toBe(false);
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
