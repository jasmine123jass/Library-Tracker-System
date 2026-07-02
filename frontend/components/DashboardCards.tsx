"use client";

import {
  BookOpen,
  BookMarked,
  CheckCircle2,
  FolderOpen,
} from "lucide-react";

const cards = [
  {
    title: "Total Books",
    value: "128",
    icon: BookOpen,
    color: "bg-blue-600",
  },
  {
    title: "Borrowed",
    value: "36",
    icon: BookMarked,
    color: "bg-red-500",
  },
  {
    title: "Available",
    value: "92",
    icon: CheckCircle2,
    color: "bg-green-500",
  },
  {
    title: "Categories",
    value: "18",
    icon: FolderOpen,
    color: "bg-purple-600",
  },
];

export default function DashboardCards() {
  return (
    <section className="grid grid-cols-1 md:grid-cols-2 xl:grid-cols-4 gap-6">

      {cards.map((card) => {

        const Icon = card.icon;

        return (

          <div
            key={card.title}
            className="rounded-2xl bg-slate-900 border border-slate-800 p-6 shadow-lg hover:scale-[1.03] transition-all duration-300"
          >

            <div className="flex justify-between items-center">

              <div>

                <p className="text-slate-400 text-sm">

                  {card.title}

                </p>

                <h2 className="text-4xl font-bold mt-2">

                  {card.value}

                </h2>

              </div>

              <div
                className={`w-14 h-14 rounded-xl flex items-center justify-center ${card.color}`}
              >

                <Icon size={28} className="text-white" />

              </div>

            </div>

          </div>

        );

      })}

    </section>
  );
}