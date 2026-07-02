import Sidebar from "@/components/Sidebar";
import Navbar from "@/components/Navbar";
import DashboardCards from "@/components/DashboardCards";
import BooksTable from "@/components/BooksTable";

export default function Home() {
  return (
    <main className="flex min-h-screen bg-slate-950">

      <Sidebar />

      <section className="flex-1 flex flex-col">

        <Navbar />

        <div className="p-8">

          <h1 className="text-3xl font-bold mb-8">
            Dashboard
          </h1>

          <DashboardCards />

          <BooksTable />

        </div>

      </section>

    </main>
  );
}