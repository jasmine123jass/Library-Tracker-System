"use client";

import {
  LayoutDashboard,
  BookOpen,
  BarChart3,
  Settings,
} from "lucide-react";

export default function Sidebar() {
  return (
    <aside className="w-64 min-h-screen bg-slate-900 border-r border-slate-800 p-6">

      <h1 className="text-3xl font-bold text-blue-500 mb-10">
        📚 Library
      </h1>

      <nav className="space-y-3">

        <button className="flex items-center gap-3 w-full px-4 py-3 rounded-xl bg-blue-600 hover:bg-blue-700 transition">
          <LayoutDashboard size={20} />
          Dashboard
        </button>

        <button className="flex items-center gap-3 w-full px-4 py-3 rounded-xl hover:bg-slate-800 transition">
          <BookOpen size={20} />
          Books
        </button>

        <button className="flex items-center gap-3 w-full px-4 py-3 rounded-xl hover:bg-slate-800 transition">
          <BarChart3 size={20} />
          Statistics
        </button>

        <button className="flex items-center gap-3 w-full px-4 py-3 rounded-xl hover:bg-slate-800 transition">
          <Settings size={20} />
          Settings
        </button>

      </nav>

    </aside>
  );
}