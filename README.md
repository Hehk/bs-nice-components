# Nice Components

This is an attempt to bring the styled-components/glamorous style of component creation to reason. I do this by creating
a wrapper around the bs-nice library.

```re
module Title = (val NiceComponents.h1([|
 Color(White),
 TextAlign(Center),
 Raw("font-size", "1.5em")
|]));

module Wrapper = (val NiceComponents.section([|
  BackgroundColor(Hex("db4d3f")),
  Padding(Em(4.))
|]));

let component = ReasonReact.statelessComponent("HelloWorld");

let make = _children => {
  ...component,
  render: _self => <Wrapper> <Title> (ReasonReact.stringToElement("Hello World!")) </Title> </Wrapper>
};
```

# Install

```
npm install --save bs-nice-components
```

# State

This is currently very early days. Expect this library to very volatile as I make changes in the future.

## Todo
[ ] Create a macro to generate the tag functions
[ ] Add a type safe way to pass parameters to components
[ ] make the whole world beautiful... and type-safe :P
