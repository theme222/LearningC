(self.webpackChunk_N_E = self.webpackChunk_N_E || []).push([
  [974],
  {
    3792: (e, t, s) => {
      "use strict";
      s.r(t), s.d(t, { default: () => n });
      var o = s(5155),
        r = s(2115);
      function n() {
        let [e, t] = (0, r.useState)(""),
          [s, n] = (0, r.useState)(""),
          [a, l] = (0, r.useState)(!1),
          [d, c] = (0, r.useState)(""),
          [i, u] = (0, r.useState)(!1),
          [m, x] = (0, r.useState)("");
        (0, r.useEffect)(
          () => (
            (document.body.style.backgroundImage =
              "url('/img/background.png')"),
            (document.body.style.backgroundSize = "cover"),
            (document.body.style.backgroundRepeat = "no-repeat"),
            (document.body.style.backgroundPosition = "center"),
            () => {
              (document.body.style.backgroundImage = ""),
                (document.body.style.backgroundSize = ""),
                (document.body.style.backgroundRepeat = ""),
                (document.body.style.backgroundPosition = "");
            }
          ),
          []
        );
        let g = async () => {
          try {
            let e = await fetch("/api/criossant");
            if (!e.ok) throw Error("Network response was not ok");
            let t = await e.json();
            x(t.Croissant);
          } catch (e) {
            console.error("Error cooking Croissant:", e),
              c("Failed to cooking Croissant.");
          }
        };
        return (0, o.jsxs)("div", {
          className:
            "min-h-screen flex flex-col items-center justify-center text-gray-800",
          children: [
            (0, o.jsx)("p", {
              className:
                "text-5xl font-extrabold mb-8 text-center text-orange-100 drop-shadow-lg",
              children:
                "\uD83E\uDD50✨ The Croissant Shop Admin Portal ✨\uD83E\uDD50",
            }),
            i &&
              (0, o.jsxs)("div", {
                className:
                  "fixed inset-0 z-50 flex items-center justify-center bg-red-900 bg-opacity-95 animate-pulse text-white text-center",
                children: [
                  (0, o.jsxs)("div", {
                    className: "text-6xl font-extrabold animate-bounce",
                    children: [
                      "\uD83D\uDEA8 HACKER DETECTED \uD83D\uDEA8",
                      (0, o.jsx)("p", {
                        className: "text-lg mt-4 font-mono",
                        children: "This incident will be reported.",
                      }),
                    ],
                  }),
                  (0, o.jsx)("audio", {
                    autoPlay: !0,
                    children: (0, o.jsx)("source", {
                      src: "/sfx/alarm.mp3",
                      type: "audio/mpeg",
                    }),
                  }),
                ],
              }),
            a
              ? (0, o.jsxs)("div", {
                  className:
                    "bg-white bg-opacity-90 backdrop-blur-lg rounded-xl shadow-2xl p-10 w-full max-w-3xl",
                  children: [
                    (0, o.jsx)("h2", {
                      className:
                        "text-3xl font-bold text-orange-700 mb-4 text-center",
                      children: "Admin Dashboard",
                    }),
                    (0, o.jsx)("p", {
                      className: "text-lg text-center mb-6 text-gray-700",
                      children: "Our croissant inventory.",
                    }),
                    (0, o.jsxs)("div", {
                      className: "grid grid-cols-2 gap-4 text-left text-sm",
                      children: [
                        (0, o.jsxs)("div", {
                          className: "p-4 bg-orange-100 rounded-lg shadow-sm",
                          children: [
                            "\uD83E\uDD50 Butter Croissants: ",
                            (0, o.jsx)("strong", { children: "532" }),
                          ],
                        }),
                        (0, o.jsxs)("div", {
                          className: "p-4 bg-orange-100 rounded-lg shadow-sm",
                          children: [
                            "\uD83E\uDD50 Chocolate Croissants: ",
                            (0, o.jsx)("strong", { children: "287" }),
                          ],
                        }),
                        (0, o.jsxs)("div", {
                          className: "p-4 bg-orange-100 rounded-lg shadow-sm",
                          children: [
                            "\uD83E\uDD50 Almond Croissants: ",
                            (0, o.jsx)("strong", { children: "193" }),
                          ],
                        }),
                        (0, o.jsxs)("div", {
                          className: "p-4 bg-orange-100 rounded-lg shadow-sm",
                          children: [
                            "\uD83E\uDD50 Mystery Flavor: ",
                            (0, o.jsx)("strong", { children: "42" }),
                          ],
                        }),
                      ],
                    }),
                    (0, o.jsxs)("p", {
                      className:
                        "mt-6 text-center text-gray-500 text-xs italic",
                      children: [
                        "Help? ",
                        (0, o.jsx)("span", {
                          title: m,
                          className: "underline cursor-help",
                          children: "Contact",
                        }),
                        ".",
                      ],
                    }),
                  ],
                })
              : (0, o.jsxs)("div", {
                  className:
                    "bg-white bg-opacity-90 backdrop-blur-lg rounded-xl shadow-2xl p-10 w-full max-w-md",
                  children: [
                    (0, o.jsx)("h2", {
                      className:
                        "text-4xl font-bold mb-6 text-center text-orange-600",
                      children: "Admin Login",
                    }),
                    (0, o.jsxs)("form", {
                      onSubmit: (t) => {
                        t.preventDefault(),
                          "admin" === e.toLowerCase().trim() &&
                          "thank you for the music" === s.toLowerCase().trim()
                            ? (l(!0), c(""), g())
                            : (l(!1), u(!0), setTimeout(() => u(!1), 6e3));
                      },
                      className: "space-y-5",
                      children: [
                        (0, o.jsxs)("div", {
                          children: [
                            (0, o.jsx)("label", {
                              className: "block font-semibold text-sm",
                              children: "Username",
                            }),
                            (0, o.jsx)("input", {
                              className:
                                "w-full px-4 py-2 mt-1 border border-gray-300 rounded focus:outline-none focus:ring-2 focus:ring-orange-400",
                              value: e,
                              onChange: (e) => t(e.target.value),
                            }),
                          ],
                        }),
                        (0, o.jsxs)("div", {
                          children: [
                            (0, o.jsx)("label", {
                              className: "block font-semibold text-sm",
                              children: "Password",
                            }),
                            (0, o.jsx)("input", {
                              type: "password",
                              className:
                                "w-full px-4 py-2 mt-1 border border-gray-300 rounded focus:outline-none focus:ring-2 focus:ring-orange-400",
                              value: s,
                              onChange: (e) => n(e.target.value),
                            }),
                          ],
                        }),
                        (0, o.jsx)("button", {
                          type: "submit",
                          className:
                            "w-full bg-orange-500 hover:bg-orange-600 text-white font-bold py-2 rounded transition",
                          children: "Login",
                        }),
                      ],
                    }),
                    d &&
                      (0, o.jsx)("p", {
                        className:
                          "mt-4 text-red-500 font-semibold text-center",
                        children: d,
                      }),
                  ],
                }),
          ],
        });
      }
    },
    7676: (e, t, s) => {
      Promise.resolve().then(s.bind(s, 3792));
    },
  },
  (e) => {
    var t = (t) => e((e.s = t));
    e.O(0, [441, 684, 358], () => t(7676)), (_N_E = e.O());
  },
]);
