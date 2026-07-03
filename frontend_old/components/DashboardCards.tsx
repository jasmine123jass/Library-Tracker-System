"use client";

import { Book } from "@/types/book";
import {
  BookOpen,
  BookMarked,
  CheckCircle2,
  FolderOpen,
} from "lucide-react";

interface DashboardCardsProps {
  books: Book[];
}

export default function DashboardCards({
  books,
}: DashboardCardsProps) {

  const totalBooks = books.length;

  const borrowedBooks = books.filter(
    (book) => book.status === "Borrowed"
  ).length;

  const availableBooks = books.filter(
    (book) => book.status === "Available"
  ).length;

  const categories = new Set(
    books.map((book) => book.category)
  ).size;

  const cards = [
    {
      title: "Total Books",
      value: totalBooks,
      icon: BookOpen,
      color: "bg-blue-600",
    },
    {
      title: "Borrowed",
      value: borrowedBooks,
      icon: BookMarked,
      color: "bg-red-600",
    },
    {
      title: "Available",
      value: availableBooks,
      icon: CheckCircle2,
      color: "bg-green-600",
    },
    {
      title: "Categories",
      value: categories,
      icon: FolderOpen,
      color: "bg-purple-600",
    },
  ];

  return (
    <section className="grid grid-cols-1 md:grid-cols-2 xl:grid-cols-4 gap-6 my-8">

      {cards.map((card) => {

        const Icon = card.icon;

        return (

          <div
            key={card.title}
            className="bg-slate-900 rounded-2xl p-6 border border-slate-800 shadow-lg hover:scale-105 transition"
          >

            <div className="flex justify-between items-center">

              <div>

                <p className="text-slate-400">
                  {card.title}
                </p>

                <h2 className="text-4xl font-bold mt-2">
                  {card.value}
                </h2>

              </div>

              <div
                className={`w-14 h-14 rounded-xl flex justify-center items-center ${card.color}`}
              >

                <Icon className="text-white" size={28} />

              </div>

            </div>

          </div>

        );

      })}

    </section>
  );
}