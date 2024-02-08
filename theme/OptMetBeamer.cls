\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{OptMetBeamer}[2024/02/07 - From Beamer class]

\newcommand{\headlinecolor}{\normalcolor}
\LoadClass[8pt,handout,t]{beamer}

% To forget already defined environments
\let\definition\undefined \let\enddefinition\undefined
\let\lemma\undefined \let\endlemma\undefined
\let\theorem\undefined \let\endtheorem\undefined
\let\corollary\undefined \let\endcorollary\undefined
\let\proof\undefined \let\endproof\undefined
\let\problem\undefined \let\endproblem\undefined
\let\example\undefined \let\endexample\undefined
\let\oldemptyset\emptyset
\let\emptyset\varnothing

% Beamer options
\mode<presentation>
%\usetheme[secheader]{Madrid} 
\setbeamercovered{transparent}
\usefonttheme{professionalfonts}

% Packages
\RequirePackage[skins]{tcolorbox}
\RequirePackage[utf8]{inputenc}
\RequirePackage[T1]{fontenc}
\RequirePackage{amsmath}
\RequirePackage{amsfonts}
\RequirePackage{amssymb}
\RequirePackage{graphicx}
\RequirePackage{bookman}
\RequirePackage{mathtools}
\RequirePackage{etoolbox}
%\RequirePackage{enumitem}
%\RequirePackage{fontspec}
%\setmainfont{Calibri}

\geometry{paperwidth=160mm,paperheight=120mm} % 4:3 ratio.
\setbeamertemplate{background} 
{
	\includegraphics[width=\paperwidth,height=\paperheight]{background_img/background.pdf}
}
% MARGINS
\setbeamersize{text margin left=7mm,text margin right=7mm} 

% COLORS
\definecolor{univpm-fg}{RGB}{81,81,81}
\definecolor{univpm-bg}{RGB}{128,208,200}
\definecolor{univpm-red}{RGB}{196,30,58}
\definecolor{univpm-grey}{RGB}{119,114,99}
\definecolor{blue1}{RGB}{79, 129, 189}


% MAIN PALETTE
\setbeamercolor*{structure}{fg=univpm-fg,bg=univpm-bg}

\setbeamercolor*{block body}{fg=black,bg=white}
\setbeamercolor*{block title}{fg=black,bg=white}

\setbeamercolor*{palette primary}{fg=univpm-fg, bg=univpm-bg}
\setbeamercolor*{palette secondary}{fg=univpm-fg, bg=univpm-bg}
\setbeamercolor*{palette tertiary}{fg=univpm-fg, bg=univpm-bg}
\setbeamercolor*{palette quaternary}{fg=univpm-fg, bg=univpm-bg}

\setbeamercolor*{sidebar}{fg=univpm-fg, bg=univpm-bg}
  
\setbeamercolor*{palette sidebar primary}{fg=univpm-side-fg, bg=univpm-side-bg}
\setbeamercolor*{palette sidebar secondary}{fg=univpm-side-fg, bg=univpm-side-bg}
\setbeamercolor*{palette sidebar tertiary}{fg=univpm-side-fg, bg=univpm-side-bg}
\setbeamercolor*{palette sidebar quaternary}{fg=univpm-side-fg, bg=univpm-side-bg}

\setbeamercolor*{frametitle}{fg=univpm-fg,bg=white}
\setbeamercolor*{titlelike}{parent=palette primary}

\setbeamercolor*{separation line}{}
\setbeamercolor*{fine separation line}{}

% BLOCKS
\setbeamercolor*{block body}{bg=white, fg = black}
\setbeamercolor*{block title}{bg=white, fg = black}

% ITEMIZE
\setbeamertemplate{itemize item}{$\pmb{\square}$}		% $\blacksquare$
\setbeamertemplate{itemize subitem}{$\pmb{\square}$}
\setbeamercolor{itemize item}{fg=blue1}
\setbeamercolor{itemize subitem}{fg=univpm-red}

% ENUMERATE
\setbeamertemplate{enumerate items}[default]
\setbeamercolor{enumerate item}{fg=blue1}
\setbeamercolor{enumerate subitem}{fg=univpm-red}

% TOC
\setbeamercolor{section in toc}{fg=black,bg=white}
\setbeamercolor{subsection in toc}{fg=black}

% FRAMETITLE
\setbeamercolor{frametitle}{fg=black,bg=white}
\setbeamerfont{frametitle}{size=\small}
\setbeamertemplate{frametitle}{\color{black}\bfseries\vspace{2cm}\textsc{\insertframetitle}}
%\setbeamertemplate{frametitle}{\color{black}\bfseries\vspace{2cm}\insertframetitle}

% COMMANDS
\newcommand{\red}[1]{\textcolor{univpm-red}{#1}}
\newcommand{\redbf}[1]{\textbf{\textcolor{univpm-red}{#1}}}

% ENVIRONMENTS
\newenvironment{theorem}{\begin{myframe}{Teorema}}{\end{myframe}}
\newenvironment{proposition}{\begin{myframe}{Proposizione}}{\end{myframe}}
\newenvironment{lemma}{\begin{myframe}{Lemma}}{\end{myframe}}
\newenvironment{corollary}{\begin{myframe}{Corollario}}{\end{myframe}}
\newenvironment{definition}{\begin{myframe}{Definizione}}{\end{myframe}}
\newenvironment{proof}{\begin{minipage}{\textwidth}\textbf{Dimostrazione.\\} }{\end{minipage}}
\newenvironment{example}{\begin{minipage}{\textwidth}\textbf{Esempio.\\} }{\end{minipage}}


% Box for tasks (and blocks)
\newtcolorbox{myframe}[2][]{%
	enhanced,
	colback=white,
	colframe=black,
	coltitle=black,
%	sharp corners,
	boxrule=0.8pt,
	fonttitle=\itshape,
	attach boxed title to top left={yshift=-0.3\baselineskip-0.4pt,xshift=2mm},
	boxed title style={tile,size=minimal,left=0.5mm,right=0.5mm,
	colback=white,
	before upper=\strut},
	title=\textbf{#2},
	#1
}
\newtcolorbox{smallbox}[1][]{%
	enhanced,
	colback=white,
	colframe=black,
	coltitle=black,
%	sharp corners,
	boxrule=0.4pt,
	fonttitle=\itshape,
	attach boxed title to top left={yshift=-0.3\baselineskip-0.4pt,xshift=2mm},
	boxed title style={tile,size=minimal,left=0.5mm,right=0.5mm,
		colback=white,
		before upper=\strut},
%	title=\textbf{Problema},
	#1
}

% Commands
\newcommand{\norm}[1]{\left\lVert#1\right\rVert}		% norm
\newcommand{\abs}[1]{\left|#1\right|}
\newcommand{\titleframe}[2]{
	\section{#1}
	\begin{frame}[c]
		\begin{center}
			\Huge\textbf{#1}\\
			\vspace{10mm}
			\Large
			\textcolor{univpm-grey}{\textbf{#2}}
		\end{center}
	\end{frame}
}

\def\Rbb{\mathbb{R}}

