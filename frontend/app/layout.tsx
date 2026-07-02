import type { Metadata } from "next";
import "./globals.css";

export const metadata: Metadata = {
  title: "Library Tracker",
  description: "Modern Library Management Dashboard",
};

export default function RootLayout({
  children,
}: Readonly<{
  children: React.ReactNode;
}>) {
  return (
    <html lang="en">
      <body className="bg-slate-950 text-white antialiased">
        {children}
      </body>
    </html>
  );
}