% -*- coding: utf-8 -*-
% ----------------------------------------------------------------------------
% Author:  Jianrui Lyu <tolvjr@163.com>
% Website: https://lvjr.bitbucket.io/jnuthesis.html
% License: The LaTeX Project Public License 1.3
% ----------------------------------------------------------------------------

\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{jnuthesis}[2018/11/12 v0.5 A thesis class for Jinan University]

% \newif\ifsourcehan  \sourcehanfalse  % 切换思源字体

% \DeclareOption{sourcehan}{\sourcehantrue}

% \DeclareOption*{\PassOptionsToClass{\CurrentOption}{ctexart}} %其它选项

\ProcessOptions %不可省略

% 四号    小四号    五号      小五号    三号    小三号
% 14bp    12bp      10.5bp    9bp     16bp    15bp
\LoadClass[12pt,UTF8,noindent,openany]{ctexbook}
% \AtBeginDocument{\zihao{4}}

\RequirePackage[a4paper,left=30mm,right=20mm,top=25.4mm,bottom=25.4mm]{geometry}

\RequirePackage{tabu}
\RequirePackage{pifont}
\RequirePackage{lastpage}
\RequirePackage{fancyhdr}
\RequirePackage{xcolor}
\RequirePackage{comment}
\RequirePackage{environ}
\RequirePackage{etoolbox}
\RequirePackage{graphicx}
\RequirePackage{Times}

\RequirePackage{hyperref}
\hypersetup{
   pdfstartview={FitH},
   colorlinks,
   citecolor=blue,
   filecolor=blue,
   linkcolor=black,
   urlcolor=black,
   bookmarksnumbered,
   unicode=true % 避免用CJK时书签乱码
}

\setlength{\parindent}{2em}
\setlength{\linespread}{2}

% 中文信息指令
\renewcommand{\title}{A thesis class for Jinan University}
\newcommand{\biaoti}{暨南大学本科生论文模板}
\newcommand{\xueyuan}{信息科学技术学院}
\newcommand{\xuexi}{\;}
\newcommand{\zhuanye}{信息与计算科学}
\newcommand{\xingming}{暨小小}
\newcommand{\xuehao}{2018059999}
\newcommand{\daoshi}{暨大大}

% 英文信息指令
\newcommand{\name}{Chen Yushuo}
\newcommand{\stuno}{2020101918}
\newcommand{\major}{Mathematics And Apply Mathematics}
\newcommand{\supervisor}{Her-Hailong}
% \newcommand{\date}{06/03/2024}


\fancypagestyle{main}{
  \renewcommand{\headrulewidth}{0.4pt}%
  \fancyhf{}
  \chead{\small\biaoti}
  \rfoot{\small\thepage}
}

\pagestyle{main}

\newcommand{\underspace}[1]{\kern0pt\underline{\hspace{#1}}\kern0pt\relax}
\newcommand{\underbox}[2]{\kern0pt\underline{\makebox[#1]{#2}}\kern0pt\relax}
\newcommand{\underparbox}[2]{\kern0pt\underline{\parbox[b]{#1}{#2}}\kern0pt\relax}
\newcommand{\ulinefill}[1]{\xleaders\hbox{\underline{\vphantom{#1}\kern1pt}}\hfill\kern0pt}
\newcommand{\fillout}[1]{\ulinefill{#1}\underline{#1}\ulinefill{#1}}

\CTEXoptions[today=small]

% \newcommand{\entitlepage}{%英文封面
%   \thispagestyle{empty}
%   \vfill
%   \noindent Title:  \fillout{\title}
%   \vfill
%   \begin{center}
%     \begin{tabular}{l}
%       Student Name: \underbox{20em}{\name}\\[0.6em]
%       Student No.: \underbox{20em}{\stuno}\\[0.6em]
%       Major: \underbox{20em}{\major}\\[0.6em]
%       Supervisor: \underbox{20em}{\supervisor}\\[0.6em]
%       Date: \underbox{20em}{\date}\\[0.6em]
%     \end{tabular}
%   \end{center}
%   \newpage
% }

\renewcommand{\titlepage}{%中文封面
  \thispagestyle{empty}
  \vspace*{\fill}
  \noindent Title:  \fillout{\title}
  \vfill
  \begin{center}
    \begin{tabular}{l}
      Student Name: \underbox{20em}{\name}\\[0.6em]
      Student No.: \quad \underbox{20em}{\stuno}\\[0.6em]
      Major: \qquad \quad \enspace \underbox{20em}{\major}\\[0.6em]
      Supervisor: \quad \enspace \underbox{20em}{\supervisor}\\[0.6em]
      Date: \qquad \qquad \underbox{20em}{06/03/2024}\\[0.6em]
    %   Date: \underbox{20em}{\date}\\[0.6em]
    \end{tabular}
  \end{center}
  \newpage
}

\newcommand{\statement}{%
  \thispagestyle{plain}
  \begingroup
  \centerline{\textbf{Statement\ of\ Originality}}%
  \vspace{2em}
  \noindent
  I hereby declare that the thesis presented is the result of research performed by me personally, 
  under guidance from my supervisor. 
  This thesis does not contain any content (other than those cited with references) that has been previously published or written by others, 
  nor does it contain any material previously presented to other educational institutions for degree or certificate purpose to the best of my knowledge. 
  I promise that all facts presented in this thesis are true and creditable.
  \par\vspace{5.5cm}%
  \noindent Signed:\hfill Date:
  \par
  \endgroup
  \newpage
}

\newenvironment{zhabstract}{%
  \thispagestyle{plain}
  \begin{center}
    \zihao{-3}\bfseries\biaoti
  \end{center}
}{\newpage}

\newenvironment{enabstract}{%
  \thispagestyle{plain}
  \begin{center}
    \Large \bfseries\title
  \end{center}
}{\newpage}

\newcommand{\zhaiyao}{
  \vspace{0.5cm}\noindent\textbf{[摘要]\quad}
}
\newcommand{\guanjianci}{
  \par\vspace{1cm}\noindent\textbf{[关键词]\quad}
}

\newcommand{\abstract}{
  \vspace{0.5cm}\noindent\textbf{Abstract\quad}
}
\newcommand{\keywords}{
  \par\vspace{1cm}\noindent\textbf{Keywords\quad}
}

\setcounter{tocdepth}{3}
\setcounter{secnumdepth}{3} % 默认 subsubsection 不显示编号

\renewcommand{\contentsname}{\hfill Contents\hfill}

\RequirePackage{titletoc} % 2024.3.6调整目录间距
%\titlecontents{标题层次}[左间距]{上间距和整体格式}{标题序号}{标题内容}{指引线和页码}[下间距]
\titlecontents{chapter}[1em]{\addvspace{.3em}\bfseries}{\contentslabel{1em}}{}
                            {\ \titlerule*[5pt]{$\cdot$}\contentspage}[\addvspace{.3em}]
\titlecontents{section}[2.8em]{}{\contentslabel{1.8em}}{}{\ \titlerule*[5pt]{$\cdot$}\contentspage}
\titlecontents{subsection}[4.6em]{}{\contentslabel{2.6em}}{}{\ \titlerule*[5pt]{$\cdot$}\contentspage}
\titlecontents{subsubsection}[6.4em]{}{\contentslabel{3.4em}}{}{\ \titlerule*[5pt]{$\cdot$}\contentspage}

% 2024.3.6  禁用  关于章节标题的设置\huge  \Large  \large
\CTEXsetup[name={,},number={\arabic{chapter}.},
           format={\bfseries\raggedright},nameformat={\bfseries},aftername={\ }]{chapter}
\CTEXsetup[name={,},number={\arabic{chapter}.\arabic{section}},
           format={\bfseries\raggedright},nameformat={\bfseries},aftername={\ }]{section}
\CTEXsetup[name={,},number={\arabic{chapter}.\arabic{section}.\arabic{subsection}},
           format={\bfseries\raggedright},nameformat={\bfseries},aftername={\ }]{subsection}
\CTEXsetup[name={,},number={\arabic{chapter}.\arabic{section}.\arabic{subsection}.\arabic{subsubsection}},
           format={\bfseries\raggedright},nameformat={\bfseries},aftername={\ }]{subsubsection}

\newcommand\ignorepars{\@ifnextchar\par{\expandafter\ignorepars\@gobble}{}}

\InputIfFileExists{jnuthesis.cfg}{}{}

% 2024.3.6  禁用
% \newcommand{\my@set@sourcehan}{
%   \setCJKmainfont[BoldFont=Source Han Sans SC]{Source Han Serif SC}
%   \setCJKsansfont{Source Han Sans SC}
%   % 用中文字体名时 LuaTeX 找不到该字体，XeTeX 正常
%   %\setCJKmainfont[BoldFont=思源黑体]{思源宋体}
%   %\setCJKsansfont{思源黑体}
% }

% 2024.3.3  禁用中文宋体
% \ifbool{sourcehan}{
%   \RequirePackage{iftex}
%   % https://sourceforge.net/p/xetex/code/ci/master/tree/source/texk/web2c/xetexdir/NEWS
%   \ifbool{XeTeX}{ % TeXLive 2015
%     \ifdimless{\the\XeTeXversion\XeTeXrevision pt}{0.99992pt}{}{\my@set@sourcehan}
%   }{}
%   \ifbool{LuaTeX}{\my@set@sourcehan}{}
% }{}

\AtBeginDocument{
  \setlength{\abovedisplayskip}{4pt minus 2pt}
  \setlength{\belowdisplayskip}{4pt minus 2pt}
  \setlength{\abovedisplayshortskip}{2pt}
  \setlength{\belowdisplayshortskip}{2pt}
}

\setlength\arraycolsep{4pt}

\RequirePackage{CJKfntef}
\RequirePackage{multirow}
\RequirePackage{amsmath}
\RequirePackage{amssymb}

\RequirePackage{relsize}
\newcommand{\Int}{\mathop{\mathlarger{\int}}}

\newcommand{\e}{\mathrm{e}}
\newcommand{\limit}{\lim\limits}
\newcommand{\R}{\mathbb{R}}

\DeclareMathOperator{\Corr}{\rho}
\DeclareMathOperator{\Cov}{Cov}
\DeclareMathOperator{\grad}{grad}
\DeclareMathOperator{\Prj}{Prj}
\DeclareMathOperator{\Var}{Var}

\newcommand{\diff}{\mathop{}\!\mathrm{d}}
\newcommand{\dx}{\diff x}
\newcommand{\dy}{\diff y}
\def\dz{\diff z} % 不确定命令是否已经定义
\newcommand{\du}{\diff u}
\newcommand{\dv}{\diff v}
\newcommand{\dr}{\diff r}
\newcommand{\ds}{\diff s}
\newcommand{\dt}{\diff t}
\newcommand{\dS}{\diff S}
% 有些宏包比如 hyperref 会修改 \d 的定义，所以放在 document 开始处
% 利用 etoolbox 将 \d 定义为健壮命令，以避免在 align 等环境中错误地展开
\AtBeginDocument{%
  \let\oldd=\d
  \renewrobustcmd{\d}{\ifbool{mmode}{\diff}{\oldd}}%
}

\newcommand{\va}{\vec{a\vphantom{b}}}
\newcommand{\vb}{\vec{b}}
\newcommand{\vc}{\vec{c\vphantom{b}}}
\newcommand{\vd}{\vec{d}}
\newcommand{\ve}{\vec{e}}
\newcommand{\vi}{\vec{i}}
\newcommand{\vj}{\vec{j}}
\newcommand{\vk}{\vec{k}}
\newcommand{\vn}{\vec{n}}
\newcommand{\vs}{\vec{s}}
\newcommand{\vv}{\vec{v}}

\let\ov=\overrightarrow

\let\lb=\{
\let\rb=\}

\def\T{\mathrm{T}\kern-.5pt}

\newrobustcmd{\wfrac}[3][2pt]{%
  {\begingroup\hspace{#1}#2\hspace{#1}\endgroup\over\hspace{#1}#3\hspace{#1}}%
}

