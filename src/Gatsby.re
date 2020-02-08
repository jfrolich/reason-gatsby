type graphql;

// not used currently
[@bs.module "gatsby"] external graphql: 'any = "graphql";

[@bs.module "gatsby"]
external useStaticQuery: string => Js.Json.t = "useStaticQuery";

module Link = {
  [@bs.module "gatsby"] [@react.component]
  external make:
    (~children: React.element, ~_to: string, ~style: ReactDOMRe.Style.t=?) =>
    React.element =
    "Link";
};

[@bs.module "@reach/router"] external navigate: string => unit = "navigate";

// ___loader is a Gatsby global, that can enqueue routes to fetch
let hover = [%bs.raw
  {|
function(str) {
  if (___loader) {
    ___loader.hovering(str)
  }
}
|}
];
