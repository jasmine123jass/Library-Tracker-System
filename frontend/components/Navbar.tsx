"use client";

import { Bell, UserCircle } from "lucide-react";

export default function Navbar() {
  return (
    <header className="flex justify-between items-center p-6 border-b border-slate-800 bg-slate-950">

      <div>

        <h2 className="text-2xl font-bold">
          Library Tracker Dashboard
        </h2>

        <p className="text-slate-400 mt-1">
          Manage your books efficiently
        </p>

      </div>

      <div className="flex items-center gap-5">

        <button className="relative">

          <Bell size={22} />

          <span className="absolute -top-1 -right-1 w-2 h-2 rounded-full bg-red-500"></span>

        </button>

        <UserCircle size={36} />

      </div>

    </header>
  );
}