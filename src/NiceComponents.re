module type Component = {
  open ReasonReact;
  let className: string;
  let component: componentSpec(stateless, stateless, noRetainedProps, noRetainedProps, actionless);
  let make:
    (~props: Js.t({..})=?, array(reactElement)) =>
    componentSpec(stateless, stateless, noRetainedProps, noRetainedProps, actionless);
};

/* Generated Module */
let make = (~tag, ~debugName="", styles) : (module Component) =>
  (module
   {
     let component = ReasonReact.statelessComponent(debugName);
     let className = Nice.css(styles);
     let make = (~props=?, children) => {
       ...component,
       render: _self => {
         let cls = {"className": className};
         switch props {
         | None => ReasonReact.createDomElement(tag, ~props=cls, children)
         | Some(x) => ReasonReact.createDomElement(tag, ~props=Js.Obj.assign(cls, x), children)
         };
       }
     };
   });

/* Default Tags */
/* The list comes from html-tag-name */
/* TODO: create a macro to get rid of this mess */
let a = make(~tag="a");

let abbr = make(~tag="abbr");

let acronym = make(~tag="acronym");

let address = make(~tag="address");

let applet = make(~tag="applet");

let area = make(~tag="area");

let article = make(~tag="article");

let aside = make(~tag="aside");

let audio = make(~tag="audio");

let b = make(~tag="b");

let base = make(~tag="base");

let basefont = make(~tag="basefont");

let bdi = make(~tag="bdi");

let bdo = make(~tag="bdo");

let bgsound = make(~tag="bgsound");

let big = make(~tag="big");

let blink = make(~tag="blink");

let blockquote = make(~tag="blockquote");

let body = make(~tag="body");

let br = make(~tag="br");

let button = make(~tag="button");

let canvas = make(~tag="canvas");

let caption = make(~tag="caption");

let center = make(~tag="center");

let cite = make(~tag="cite");

let code = make(~tag="code");

let col = make(~tag="col");

let colgroup = make(~tag="colgroup");

let command = make(~tag="command");

let content = make(~tag="content");

let data = make(~tag="data");

let datalist = make(~tag="datalist");

let dd = make(~tag="dd");

let del = make(~tag="del");

let details = make(~tag="details");

let dfn = make(~tag="dfn");

let dialog = make(~tag="dialog");

let dir = make(~tag="dir");

let div = make(~tag="div");

let dl = make(~tag="dl");

let dt = make(~tag="dt");

let element = make(~tag="element");

let em = make(~tag="em");

let embed = make(~tag="embed");

let fieldset = make(~tag="fieldset");

let figcaption = make(~tag="figcaption");

let figure = make(~tag="figure");

let font = make(~tag="font");

let footer = make(~tag="footer");

let form = make(~tag="form");

let frame = make(~tag="frame");

let frameset = make(~tag="frameset");

let h1 = make(~tag="h1");

let h2 = make(~tag="h2");

let h3 = make(~tag="h3");

let h4 = make(~tag="h4");

let h5 = make(~tag="h5");

let h6 = make(~tag="h6");

let head = make(~tag="head");

let header = make(~tag="header");

let hgroup = make(~tag="hgroup");

let hr = make(~tag="hr");

let html = make(~tag="html");

let i = make(~tag="i");

let iframe = make(~tag="iframe");

let img = make(~tag="img");

let input = make(~tag="input");

let ins = make(~tag="ins");

let isindex = make(~tag="isindex");

let kbd = make(~tag="kbd");

let keygen = make(~tag="keygen");

let label = make(~tag="label");

let legend = make(~tag="legend");

let li = make(~tag="li");

let link = make(~tag="link");

let listing = make(~tag="listing");

let main = make(~tag="main");

let map = make(~tag="map");

let mark = make(~tag="mark");

let marquee = make(~tag="marquee");

let math = make(~tag="math");

let menu = make(~tag="menu");

let menuitem = make(~tag="menuitem");

let meta = make(~tag="meta");

let meter = make(~tag="meter");

let multicol = make(~tag="multicol");

let nav = make(~tag="nav");

let nextid = make(~tag="nextid");

let nobr = make(~tag="nobr");

let noembed = make(~tag="noembed");

let noframes = make(~tag="noframes");

let noscript = make(~tag="noscript");

let object_ = make(~tag="object");

let ol = make(~tag="ol");

let optgroup = make(~tag="optgroup");

let option = make(~tag="option");

let output = make(~tag="output");

let p = make(~tag="p");

let param = make(~tag="param");

let picture = make(~tag="picture");

let plaintext = make(~tag="plaintext");

let pre = make(~tag="pre");

let progress = make(~tag="progress");

let q = make(~tag="q");

let rb = make(~tag="rb");

let rbc = make(~tag="rbc");

let rp = make(~tag="rp");

let rt = make(~tag="rt");

let rtc = make(~tag="rtc");

let ruby = make(~tag="ruby");

let s = make(~tag="s");

let samp = make(~tag="samp");

let script = make(~tag="script");

let section = make(~tag="section");

let select = make(~tag="select");

let shadow = make(~tag="shadow");

let slot = make(~tag="slot");

let small = make(~tag="small");

let source = make(~tag="source");

let spacer = make(~tag="spacer");

let span = make(~tag="span");

let strike = make(~tag="strike");

let strong = make(~tag="strong");

let style = make(~tag="style");

let sub = make(~tag="sub");

let svg = make(~tag="svg");

let table = make(~tag="table");

let tbody = make(~tag="tbody");

let td = make(~tag="td");

let template = make(~tag="template");

let textarea = make(~tag="textarea");

let tfoot = make(~tag="tfoot");

let th = make(~tag="th");

let thead = make(~tag="thead");

let time = make(~tag="time");

let title = make(~tag="title");

let tr = make(~tag="tr");

let track = make(~tag="track");

let tt = make(~tag="tt");

let u = make(~tag="u");

let ul = make(~tag="ul");

let var = make(~tag="var");

let video = make(~tag="video");

let wbr = make(~tag="wbr");

let xmp = make(~tag="xmp");
